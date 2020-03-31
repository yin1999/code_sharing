package main

import (
	"fmt"
	"log"
	"math/rand"
	"net/http"
	"net/url"
	"sync"
	"text/template"
	"time"
)

type timeURL struct {
	Time int64
	URL  string
}

type serveMux struct{}

var letterBytes = []byte("abcdefghijklmnopqrstuvwxyz123456789")

var keyValue map[string]timeURL
var urlExist map[string]string

func main() {
	fmt.Println("Running!")
	wg := new(sync.WaitGroup)
	wg.Add(3)
	mux := serveMux{}
	keyValue = make(map[string]timeURL)
	urlExist = make(map[string]string)
	tmpStruct := timeURL{}
	tmpStruct.Time = time.Now().Unix()
	tmpStruct.URL = "https://gitee.com/allo123/code_sharing/tree/master/培训/物联网设备认证/示例.cpp"
	keyValue["u4dyrg"] = tmpStruct
	tmpStruct.URL = "https://gitee.com/allo123/code_sharing/tree/master/Random working/短链接"
	keyValue["njhpqd"] = tmpStruct
	rand.Seed(time.Now().Unix())
	d := time.Duration(time.Hour * 6)
	t := time.NewTicker(d)
	go func() {
		err := http.ListenAndServe(":80", &mux)
		if err != nil {
			log.Println(err)
		}
		wg.Done()
	}()
	go func() {
		http.Handle("/img/", http.StripPrefix("/img/", http.FileServer(http.Dir("./web/img"))))
		http.Handle("/css/", http.StripPrefix("/css/", http.FileServer(http.Dir("./web/css"))))
		http.Handle("/js/", http.StripPrefix("/js/", http.FileServer(http.Dir("./web/js"))))
		http.HandleFunc("/goto/", shortURL)
		http.HandleFunc("/add/", addURL)
		http.HandleFunc("/", rootHandler)
		err := http.ListenAndServeTLS(":443", "./3358091_hhuiot.xyz.pem", "./3358091_hhuiot.xyz.key", nil)
		if err != nil {
			log.Println(err)
		}
		wg.Done()
	}()
	go func() {
		i := 0
		var timeNow int64
		for {
			<-t.C
			timeNow = time.Now().Unix()
			for k, v := range keyValue {
				if timeNow-v.Time > 3600*24*15 {
					delete(urlExist, v.URL)
					delete(keyValue, k)
				}
			}
			i++
			if i == 4*7 {
				rand.Seed(time.Now().Unix())
			}
		}
	}()
	wg.Wait()
}

func (t *serveMux) ServeHTTP(w http.ResponseWriter, r *http.Request) {
	redirectHTTP(w, r)
}

func rootHandler(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/" {
		notFound(w, r)
		return
	}
	t, err := template.ParseFiles("./web/html/index.html")
	if err != nil {
		log.Println(err)
		fmt.Fprintf(w, "Error\n 服务器资源访问错误")
	} else {
		t.Execute(w, nil)
	}
}

func shortURL(w http.ResponseWriter, r *http.Request) {
	s := r.URL.Path[6:]
	if v, ok := keyValue[s]; ok {
		http.Redirect(w, r, v.URL, 301)
		v.Time = time.Now().Unix()
		keyValue[s] = v
		fmt.Printf("shortURL:%s -> %s\n", s, v.URL)
	} else {
		t, err := template.ParseFiles("./web/html/ShortURLNotFound.html")
		if err != nil {
			log.Println(err)
			fmt.Fprintf(w, "Error\n 服务器资源访问错误")
		} else {
			t.Execute(w, s)
		}
	}
}

func addURL(w http.ResponseWriter, r *http.Request) {
	URL := r.URL.Path[5:]
	if URL == "" {
		if r.Method == "GET" {
			//fmt.Println("get")
			t, err := template.ParseFiles("./web/html/shortURL.html")
			if err != nil {
				log.Println(err)
				fmt.Fprintln(w, "服务器资源访问错误")
			} else {
				err = t.Execute(w, nil)
				if err != nil {
					log.Println(err)
				}
			}
			return
		}
		//fmt.Println("post")
		err := r.ParseForm()
		if err != nil {
			log.Println(err)
			return
		}
		if r.FormValue("mod") == "0" {
			URL = r.FormValue("url")
		} else {
			// 还原短链接
		}

	} else {
		u, err := url.Parse(URL)
		if err != nil {
			log.Println(err)
			fmt.Fprintln(w, "服务器资源访问错误")
			return
		}
		if u.Scheme == "" {
			URL = "http://" + u.String()
		} else {
			URL = u.String()
		}
	}
	var newURL string
	var ok bool
	if newURL, ok = urlExist[URL]; !ok {
		newURL = randStringBytesRmndr()
		_, ok := keyValue[newURL]
		i := 0
		for ; ok; i++ {
			if i >= 5 {
				rand.Seed(time.Now().Unix())
				i = 0
			}
			newURL = randStringBytesRmndr()
			_, ok = keyValue[newURL]
		}
		keyValue[newURL] = timeURL{
			Time: time.Now().Unix(),
			URL:  URL,
		}
		urlExist[URL] = newURL
	} else {
		tmp := keyValue[newURL]
		tmp.Time = time.Now().Unix()
		keyValue[newURL] = tmp
	}
	t, err := template.ParseFiles("./web/html/addShortURL.html")
	if err != nil {
		log.Panicln(err)
		fmt.Fprintf(w, "Error\n 服务器资源访问错误")
	} else {
		t.Execute(w, newURL)
	}
	fmt.Printf("addURL:%s -> %s\n", newURL, URL)
}

func randStringBytesRmndr() string {
	b := make([]byte, 6)
	for i := 0; i < 6; i++ {
		b[i] = letterBytes[rand.Int63()%int64(len(letterBytes))]
	}
	return string(b)
}

func redirectHTTP(w http.ResponseWriter, r *http.Request) {
	// r.ParseForm()
	s := "https://hhuiot.xyz" + r.URL.Path
	http.Redirect(w, r, s, 302)
}

func notFound(w http.ResponseWriter, r *http.Request) {
	t, err := template.ParseFiles("./web/html/NotFound.html")
	if err != nil {
		log.Println(err)
		fmt.Fprintf(w, "Error\n 服务器资源访问错误")
	} else {
		t.Execute(w, r.URL.Path)
	}
}
