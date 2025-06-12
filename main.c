#include <stdio.h>
#include <stdlib.h>

/**
 * Читает весь файл в динамически выделенный буфер.
 * @param filename — имя файла для чтения.
 * @param out_size — адрес переменной, куда запишется размер прочитанных данных (в байтах).
 * @return Указатель на буфер с содержимым файла (с добавленным нуль-терминатором),
 *         или NULL при ошибке (переменная out_size остаётся неинициализированной).
 *         Освобождать через free().
 */
char *read_file_to_buffer(const char *filename, size_t *out_size) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    // Перейти в конец и узнать размер
    if (fseek(fp, 0, SEEK_END) != 0) {
        perror("fseek");
        fclose(fp);
        return NULL;
    }
    long filesize = ftell(fp);
    if (filesize < 0) {
        perror("ftell");
        fclose(fp);
        return NULL;
    }
    rewind(fp);

    // Выделить буфер (+1 байт для '\0', если понадобится строка)
    char *buffer = malloc((size_t) filesize + 1);
    if (!buffer) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Считать всё сразу
    size_t read_bytes = fread(buffer, 1, (size_t) filesize, fp);
    if (read_bytes != (size_t) filesize) {
        fprintf(stderr, "fread: ожидается %ld байт, прочитано %zu байт\n",
                filesize, read_bytes);
        free(buffer);
        fclose(fp);
        return NULL;
    }
    buffer[read_bytes] = '\0'; // нуль-терминатор, если нужно трактовать как строку

    fclose(fp);
    *out_size = read_bytes;
    return buffer;
}

int main(void) {
    const char *path = "examples/t.json";
    size_t size;
    char *data = read_file_to_buffer(path, &size);
    if (!data) {
        // Ошибка уже выведена в stderr
        return EXIT_FAILURE;
    }

    printf("Прочитано %zu байт из файла '%s'\n", size, path);
    printf("Содержимое:\n%s\n", data);

    free(data);
    return EXIT_SUCCESS;
}
