#include <stdio.h>
#include <stdlib.h>
#include <immintrin.h>

#define HEADER_SIZE 54
#define WIDTH 1200
#define HEIGHT 1200
#define NEW_WIDTH 600
#define NEW_HEIGHT 600

void resizeImage(char *inputData, char *outputData) {
    for (int j = 0; j < NEW_HEIGHT; j++) {
        for (int i = 0; i < NEW_WIDTH; i++) {
            int source_index = ((j * 2) * WIDTH + (i * 2)) * 3;
            int dest_index = (j * NEW_WIDTH + i) * 3;

            __m256i sum_vec = _mm256_setzero_si256();

            for (int k = 0; k < 3; k += 32) {
                __m256i source_vec = _mm256_loadu_si256((__m256i*)&inputData[source_index + k]);
                __m256i next_vec = _mm256_loadu_si256((__m256i*)&inputData[source_index + 3 + k]);
                sum_vec = _mm256_add_epi8(sum_vec, _mm256_avg_epu8(source_vec, next_vec));
            }

            _mm256_storeu_si256((__m256i*)&outputData[dest_index], sum_vec);
        }
    }
}

void invertColors(char *outputData) {
    __m256i max_value = _mm256_set1_epi8(255);

    for (int i = 0; i < NEW_WIDTH * NEW_HEIGHT * 3; i += 32) {

        __m256i data_vec = _mm256_loadu_si256((__m256i*)&outputData[i]);

        __m256i inverted_vec = _mm256_sub_epi8(max_value, data_vec);

        _mm256_storeu_si256((__m256i*)&outputData[i], inverted_vec);
    }
}

int main() {
    FILE *origin = fopen("/space_image.bmp", "rb");
    FILE *output = fopen("space_new.bmp", "wb+");

    char *header = (char*) malloc(HEADER_SIZE * sizeof(char));
    char *originData = (char*) malloc((WIDTH * HEIGHT * 3) * sizeof(char));
    char *resizedData = (char*) malloc((NEW_WIDTH * NEW_HEIGHT * 3) * sizeof(char));

    fread(header, sizeof(char), HEADER_SIZE, origin);
    fread(originData, sizeof(char), WIDTH * HEIGHT * 3, origin);

    resizeImage(originData, resizedData);

    invertColors(resizedData);

    *(int*)&header[18] = NEW_WIDTH;
    *(int*)&header[22] = NEW_HEIGHT;

    fwrite(header, sizeof(char), HEADER_SIZE, output);
    fwrite(resizedData, sizeof(char), NEW_WIDTH * NEW_HEIGHT * 3, output);

    fclose(origin);
    fclose(output);

    free(header);
    free(originData);
    free(resizedData);

    return 0;
}