# IO流

- [IO流](#io流)
  - [控制台IO流](#控制台io流)
    - [scanf&printf](#scanfprintf)
    - [getchar&putchar](#getcharputchar)
  - [文件IO流](#文件io流)
    - [fopen&fclose](#fopenfclose)
  - [总结](#总结)


## 控制台IO流

### scanf&printf

**scanf**格式化输入，可以要求按指定格式输入，不接受TAB,回车(换行),空格,等。  
**printf**格式化输出，按指定格式输出。

    #include <stdio.h>

    int main() {
        int a, b;
        scanf("%dhello%d",&a, &b);  //使用了指针
        printf("%d,%d", a, b);      //没有使用指针
        return 0;
    }

**思考**：为什么scanf使用指针而printf没有使用指针？

### getchar&putchar

**getchar**从标准输入缓冲区获得一个字符，与**scanf**不同，可以接受TAB,回车(换行),空格,等。  
**putchar**向标准输出缓冲区写入一个字符

    #include <stdio.h>

    int main() {
        int ch;
        while ((ch = getchar()) && ch != '\n') {
            putchar(ch);
        }
        putchar('\n');
        return 0;
    }

## 文件IO流

### fopen&fclose

__fopen( const char *restrict filename, const char *restrict mode )__ 打开文件，输入两个参数，**filename**文件路径(字符串)，**mode**打开模式(字符串)
| 文件访问模式字符串 | 含义 | 解释 | 若文件已存在的动作 | 若文件不存在的动作 |  
| ---------------- | ---- | ---- | ---------------- | ---------------- |
| "r"              | 读   | 打开文件以读取 | 从头读   | 打开失败          |
| "w"              | 写   | 创建文件以写入 | 销毁内容 | 创建新文件        |
| "a"              | 后附 | 后附到文件     | 写到结尾 | 创建新文件        |
| "r+"             | 读扩展 | 打开文件以读/写 | 从头读 | 错误             |
| "w+"             | 写扩展 | 创建文件以读/写 | 销毁内容 | 创建新文件     |
| "a+"             | 后附扩展 | 打开文件以读/写 | 写到结尾 | 创建新文件    |

__fclose( FILE *stream )__ 关闭文件，舍弃读取缓冲数据，写入缓冲数据会被写入到文件中(若有未写入的)，然后接除流与文件的关联。

__文件输入流__:

    #include <stdio.h>
    #include <stdlib.h>
    
    int main(void) {
        FILE* fp = fopen("test.txt", "r");
        if(!fp) {
            perror("File opening failed");
            return EXIT_FAILURE;
        }
    
        int c;
        while ((c = fgetc(fp)) != EOF) { // 标准C I/O读取文件循环
        putchar(c);
        }
    
        if (ferror(fp))
            puts("I/O error when reading");
        else if (feof(fp))
            puts("End of file reached successfully");
    
        fclose(fp);
        return 0;
    }

__文件输出流__:

    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        FILE* fp = fopen("test.txt", "w");
        char str[] = "Hello world";
        int i = 0;
        for (; str[i] != 0; i++) {
            fputc(str[i], fp);
        }

        if (ferror(fp))
            puts("I/O error when writing\n");
        fclose(fp);
        return 0;
    }

## 总结

标准输入输出流(特别是文件的输入输出流)在勤使用的状态下很快就能掌握。需要注意的一点是文件的输入输出流要记得关闭流与文件的关联。虽然在绝大多数的情况下，在main函数退出前会自动调用fclose解除关联。不排除少数文件写入错误的情况。

    #include <stdio.h>
    #include <stdlib.h>

    int main()
    {
        FILE* fp = fopen("test.txt", "w");
        char str[] = "Hello world";
        int i = 0;
        for (; str[i] != 0; i++) {
            fputc(str[i], fp);
        }

        if (ferror(fp))
            puts("I/O error when writing\n");
        fp = fopen("test.txt", "w");          //在未解除关联的情况下直接打开并写入一个字节，造成了错误
        fputc(0, fp);
        return 0;
    }
