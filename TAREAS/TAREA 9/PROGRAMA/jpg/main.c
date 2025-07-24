#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"          // Para cargar JPG

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"    // Para guardar JPG o PNG

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s imagen_entrada.jpg imagen_salida.jpg\n", argv[0]);
        return 1;
    }

    int width, height, channels;
    // Cargar imagen (canales originales)
    unsigned char *img = stbi_load(argv[1], &width, &height, &channels, 0);
    if (!img) {
        fprintf(stderr, "Error: No se pudo cargar la imagen %s\n", argv[1]);
        return 1;
    }
    if (channels < 3) {
        fprintf(stderr, "Error: La imagen debe tener al menos 3 canales (RGB)\n");
        stbi_image_free(img);
        return 1;
    }

    // Convertir a escala de grises (manteniendo el canal alfa si existe)
    for (int i = 0; i < width * height; i++) {
        unsigned char r = img[i * channels + 0];
        unsigned char g = img[i * channels + 1];
        unsigned char b = img[i * channels + 2];
        unsigned char gray = (unsigned char)(0.299f * r + 0.587f * g + 0.114f * b);
        img[i * channels + 0] = gray;
        img[i * channels + 1] = gray;
        img[i * channels + 2] = gray;
        // Si hay canal alfa (channels==4) se deja intacto
    }

    // Guardar imagen salida (con misma cantidad de canales)
    int success = stbi_write_jpg(argv[2], width, height, channels, img, 100);
    stbi_image_free(img);

    if (!success) {
        fprintf(stderr, "Error: No se pudo guardar la imagen %s\n", argv[2]);
        return 1;
    }

    printf("Imagen convertida a escala de grises guardada en %s\n", argv[2]);
    return 0;
}
