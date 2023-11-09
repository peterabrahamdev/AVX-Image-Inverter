## [EN](#avx-image-resizer-and-color-inverter) [ES](#avx-cambiador-de-tamaño-de-imagen-e-inversor-de-color) [HU](#avx-képátméretező-és-színinverter)
# AVX Image Resizer and Color Inverter
This simple C program reads a BMP image, resizes it to a new dimension (600x600), and inverts its colors. The resized and color-inverted image is then saved as a new BMP file.

For a detailed insight of how I made this program check out [this article](https://peterabraham.com/article/resizing-images-and-inverting-pixels-using-avx-in-c-a-step-by-step-guide-part-1) that I wrote on this topic.

## Usage
1. Clone the repository:  
```bash
git clone https://github.com/peterabrahamdev/AVX-Image-Inverter.git
```
2. Compile the program:  
```bash
gcc image_processor.c -o image_processor -mavx2
```
3. Run the program:  
```bash
./image_processor
```
4. Check the output in the space_new.bmp file.

## Requirements
GCC compiler
AVX2 support for processor

## BMP Image Details
- Input image: space_image.bmp
- Output image: space_new.bmp
- Initial image size: 1200x1200
- Resized image size: 600x600

## Implementation Details
The program uses SIMD (Single Instruction, Multiple Data) with AVX2 instructions for efficient image processing. It includes functions for resizing the image and inverting colors.

Feel free to modify the input image, output file names, or adjust the dimensions in the source code to fit your specific needs.

Note: Make sure your input image is in BMP format for proper processing.

-------------------------------------    

# AVX Cambiador de Tamaño de Imagen e Inversor de Color
Este sencillo programa en C lee una imagen BMP, la redimensiona a una nueva dimensión (600x600) e invierte sus colores. La imagen redimensionada e invertida en colores se guarda como un nuevo archivo BMP.

Para obtener una visión detallada de cómo hice este programa, consulta [este artículo](https://peterabraham.com/article/resizing-images-and-inverting-pixels-using-avx-in-c-a-step-by-step-guide-part-1) que escribí sobre este tema.

## Uso
1. Clona el repositorio:  
```bash
git clone https://github.com/peterabrahamdev/AVX-Image-Inverter.git
```
2. Compila el programa:  
```bash
gcc image_processor.c -o image_processor -mavx2
```
3. Ejecuta el programa:  
```bash
./image_processor
```
4. Verifica la salida en el archivo space_new.bmp.

## Requisitos
Compilador GCC
Soporte AVX2 para el procesador

## Detalles de la Imagen BMP
- Imagen de entrada: space_image.bmp
- Imagen de salida: space_new.bmp
- Tamaño inicial de la imagen: 1200x1200
- Tamaño de la imagen iedimensionada: 600x600

## Detalles de Implementación
El programa utiliza SIMD (Single Instruction, Multiple Data) con instrucciones AVX2 para un procesamiento eficiente de imágenes. Incluye funciones para redimensionar la imagen e invertir los colores.

Siéntete libre de modificar la imagen de entrada, los nombres de los archivos de salida o ajustar las dimensiones en el código fuente según tus necesidades específicas.

Nota: Asegúrate de que tu imagen de entrada esté en formato BMP para un procesamiento adecuado.

-------------------------------------  

# AVX Képátméretező és Színinverter
Ez a egyszerű C program beolvassa a BMP képet, átméretezi azt egy új dimenzióra (600x600), és invertálja a színeit. A méretezett és színinvertált kép új BMP fájlba kerül mentésre.

A program elkészítésének részleteiért nézd meg [ezt a cikket](https://peterabraham.com/article/resizing-images-and-inverting-pixels-using-avx-in-c-a-step-by-step-guide-part-1), amit írtam a témáról.

## Használat
1. Repository klónozása:
```bash
git clone https://github.com/peterabrahamdev/AVX-Image-Inverter.git
```
2. Program lefordítása:
```bash
gcc image_processor.c -o image_processor -mavx2
```
3. Program lefuttatása:
```bash
./image_processor
```
4. Ellenőrizd a kimenetet a space_new.bmp fájlban.

## Követelmények
GCC fordító
AVX2 támogatás a processzorban

## BMP kép részletei
- Bemeneti kép: space_image.bmp
- Kimeneti kép: space_new.bmp
- Kezdeti kép kérete: 1200x1200
- Átméretezett kép kérete: 600x600

## Megvalósítás részletei
A program SIMD (Single Instruction, Multiple Data) AVX2 utasításokat használ hatékony képfeldolgozáshoz. Tartalmaz funkciókat a kép átméretezéséhez és a színek invertálásához.

Nyugodtan módosítsd a bemeneti képet, a kimeneti fájl neveit, vagy igazítsd az dimenziókat a forráskódban az igényeidnek megfelelően.

Megjegyzés: Győződj meg róla, hogy a bemeneti képed BMP formátumban van a megfelelő feldolgozáshoz.
