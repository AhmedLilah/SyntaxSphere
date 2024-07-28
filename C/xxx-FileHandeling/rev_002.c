#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct stack {
        int integer;
        double floating;
}Stack;

int main()
{
        FILE* fp;
        fp = fopen("text.txt", "r");
        int64_t i = 0;
        char ch;
        while ((ch = fgetc(fp)) != EOF)
        {
                i += 1;
        }
        char* buffer;
        buffer = (char*)calloc(i, sizeof(char));
        fseek(fp, 0, SEEK_SET);
        fread(buffer, i * 1, 1, fp);
        printf("%s\n", buffer);
        fclose(fp);
        for (int j = 0; j < i; j++)
        {
                if ((buffer[j] != 32) && (buffer[j] != 48))
                {
                        printf("%c", buffer[j]);
                }
        }


        Stack ahmed;
        ahmed.floating = 50.01;
        printf("%f", ahmed.floating);


        free(buffer);
        return 0;
}
