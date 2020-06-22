package main

import (
	// "fmt"

	"io/ioutil"
	"log"
	"os"
	"os/signal"
	"path/filepath"
	"strings"
	"sync"
	"time"
)

var (
	selfName     string
	isCurrentDir bool
)

func main() {
	fileDir := ""
	isCurrentDir = false
	// fmt.Println("请输入要管理的文件路径(直接回车为当前路径):")	//for console with windowsgui
	// fmt.Scanln(&fileDir)
	fileDir = filepath.Dir(fileDir) + "\\"
	if !isDir(fileDir) {
		log.Println(fileDir, "is not a Dir.")
		return
	}
	if fileDir == ".\\" {
		isCurrentDir = true
		selfNameSilce := strings.Split(os.Args[0], "\\")
		selfName = selfNameSilce[len(selfNameSilce)-1]
	}
	ch := make(chan byte, 1)
	wg := new(sync.WaitGroup)
	wg.Add(2)
	go func() {
		ticker := time.NewTicker(2 * time.Minute)
		pathDelFile(fileDir)
		flag := true
		for flag {
			select {
			case <-ticker.C:
				pathDelFile(fileDir)
			case <-ch:
				flag = false
			}
		}
		wg.Done()
	}()
	go func() {
		c := make(chan os.Signal, 1)
		signal.Notify(c, os.Interrupt, os.Kill)
		<-c
		log.Println("Exit.")
		ch <- 1
		wg.Done()
	}()
	wg.Wait()
}

// func exists(path string) bool {
// 	_, err := os.Stat(path)
// 	if err != nil {
// 		if os.IsExist(err) {
// 			return true
// 		}
// 		return false
// 	}
// 	return true
// }

func isDir(path string) bool {
	s, err := os.Stat(path)
	if err != nil {
		return false
	}
	return s.IsDir()
}

type fileInfo struct {
	modTime int64
	file    string
}

func pathDelFile(path string) {
	log.Println("start.")
	files, err := ioutil.ReadDir(path)
	if err != nil {
		log.Println(err)
		return
	}
	fileDict := make(map[string]fileInfo)
	for _, f := range files {
		fileName := f.Name()
		if isCurrentDir && fileName == selfName {
			continue
		}
		fileModTime := f.ModTime().Unix()
		file := path + fileName
		mainName := strings.Split(fileName, ".")[0]
		if v, ok := fileDict[mainName]; ok {
			if v.modTime < fileModTime {
				err = os.Remove(v.file)
				if err != nil {
					log.Println(err)
				} else {
					log.Println("Deleted:", fileName)
				}
				fileDict[mainName] = fileInfo{file: file, modTime: fileModTime}
			} else {
				err = os.Remove(file)
				if err != nil {
					log.Println(err)
				} else {
					log.Println("Deleted:", fileName)
				}
			}
		} else {
			fileDict[mainName] = fileInfo{file: file, modTime: fileModTime}
		}
	}
	log.Println("Wait for 2 minutes.")
}
