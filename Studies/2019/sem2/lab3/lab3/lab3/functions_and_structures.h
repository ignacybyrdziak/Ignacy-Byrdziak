#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct RGB
{
	unsigned char R;
	unsigned char G;
	unsigned char B;
} RGB;

typedef struct Bitmap_File				//Bitmap file header
{
	short BMP_Type;
	short Helper1;
	short Helper2;
	int BMP_Size;
	int BMP_Offset;
} Bitmap_File;

typedef struct Bitmap_Info				//Bitmap info header
{
	short BMP_Planes;
	short BMP_Bits_Per_Pixel;
	int BMP_Compression;
	int BMP_Data_Size;
	int BMP_Width;
	int HDR_Size;
	int BMP_Height;
	int XPixels_pm;						//per meter
	int YPixels_pm;						//per meter
	int BMP_Colors;
	int BMP_Important_Colors;
} Bitmap_Info;

void Monochrome(char *In_File, char *Out_File, Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr);

void Read_Bitmap(char *BMP_Name, Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr);

void Make_Gray(char *Out_File, Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr);

void Pixels_To_Table(Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr);

