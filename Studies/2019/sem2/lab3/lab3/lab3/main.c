#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_and_structures.h"

int main()
{
	Bitmap_File File_head;
	Bitmap_File *fHead_ptr = &File_head;
	Bitmap_Info Info_head;
	Bitmap_Info *iHead_ptr = &Info_head;

	Read_Bitmap("picture.bmp", iHead_ptr, fHead_ptr);
	Monochrome("picture.bmp",  "test.bmp", iHead_ptr, fHead_ptr);

	return 0;
}