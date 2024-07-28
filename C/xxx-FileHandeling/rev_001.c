#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct File{
        char * content;
        int64_t size;
} File;

File openTextFile(const char * t, const char * mode);

int main()
{
        File file = openTextFile("text.txt", "r");
        printf("%s",file.content);
        printf("%s", "My Designer is: Ahmed S. Lilah");
        printf("%s", "My Designer is: Ahmed S. Lilah");
        free(file.content);
        file.content = NULL;
        return 0;
}

File openTextFile(const char * fileName, const char * mode) {
        FILE *fp;
        fp = fopen(fileName, mode);
        int64_t i =0;
        char ch;
        while ((ch = fgetc(fp)) != EOF) {
                i+=1;
        }
        int64_t size = i+1;
        char *buffer = malloc(size);
        buffer[size-1] = 0;
        fseek(fp, 0, SEEK_SET);
        fread(buffer,i*1,1,fp);
        fclose(fp);
        File file = {buffer, size};
        return file;
}
