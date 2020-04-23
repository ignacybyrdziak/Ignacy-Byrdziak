#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions_and_structures.h"

void Read_Bitmap(char *BMP_Name, Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr)
{
	FILE *file;
	if (file = fopen(BMP_Name, "rb"))								
	{	
		fread(&File_Ptr->BMP_Type, 2, 1, file);						//file header
		fread(&File_Ptr->Helper1, 2, 1, file);
		fread(&File_Ptr->Helper2, 2, 1, file);
		fread(&File_Ptr->BMP_Size, 4, 1, file);
		fread(&File_Ptr->BMP_Offset, 4, 1, file);

		fread(&Info_Ptr->BMP_Planes, 2, 1, file);					//info header
		fread(&Info_Ptr->BMP_Bits_Per_Pixel, 2, 1, file);
		fread(&Info_Ptr->BMP_Compression, 4, 1, file);
		fread(&Info_Ptr->BMP_Data_Size, 4, 1, file);
		fread(&Info_Ptr->BMP_Width, 4, 1, file);
		fread(&Info_Ptr->HDR_Size, 4, 1, file);
		fread(&Info_Ptr->BMP_Height, 4, 1, file);
		fread(&Info_Ptr->XPixels_pm, 4, 1, file);
		fread(&Info_Ptr->YPixels_pm, 4, 1, file);
		fread(&Info_Ptr->BMP_Colors, 4, 1, file);
		fread(&Info_Ptr->BMP_Important_Colors, 4, 1, file);
	}
	fclose(file);
}

void Make_Gray(char *Out_File, Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr)
{
	RGB ** RGB1;
	RGB1 = malloc(sizeof(RGB*) * Info_Ptr->BMP_Height);
	short padding = (Info_Ptr->BMP_Width * 3) % 4 ? 4 - (Info_Ptr->BMP_Width * 3) % 4 : 0;
	for (int i = 0; i < Info_Ptr->BMP_Height; i++, fseek(Out_File, padding, SEEK_CUR)) {
		for (int j = 0; j < Info_Ptr->BMP_Width; j++)
		{
			char Gray = (char)(0.229*RGB1[i][j].R + 0.587*RGB1[i][j].G + 0.114*RGB1[i][j].B);
			fputc(Gray, Out_File);
			fputc(Gray, Out_File);
			fputc(Gray, Out_File);
		}
	}
}

void Pixels_To_Table(Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr)
{
	FILE *File;
	short padding = (Info_Ptr->BMP_Width * 3) % 4 ? 4 - (Info_Ptr->BMP_Width * 3) % 4 : 0;
	RGB ** RGB1;
	RGB1 = malloc(sizeof(RGB*) * Info_Ptr->BMP_Height);
	fseek(File, File_Ptr->BMP_Offset, SEEK_SET);							
	for (int i = 0; i < Info_Ptr->BMP_Height; i++, fseek(File, padding, SEEK_CUR))
		for (int j = 0; j < Info_Ptr->BMP_Width; j++)
		{
			RGB1[i][j].B = fgetc(File);
			RGB1[i][j].G = fgetc(File);
			RGB1[i][j].R = fgetc(File);
		}
}

void Monochrome(char *In_File, char *Out_File, Bitmap_Info *Info_Ptr, Bitmap_File *File_Ptr)
{
	FILE *File;
	if (File = fopen(In_File, "rb"))
	{
		int i, j;
		RGB ** RGB1;
		RGB1 = malloc(sizeof(RGB*) * Info_Ptr->BMP_Height);

		for (i = 0; i < Info_Ptr->BMP_Height; i++)
			RGB1[i] = (RGB**)malloc(sizeof(RGB) * Info_Ptr->BMP_Width);

		short padding = (Info_Ptr->BMP_Width * 3) % 4 ? 4 - (Info_Ptr->BMP_Width * 3) % 4 : 0;		//padding bitmap																			

		Pixels_To_Table(Info_Ptr, File_Ptr);

		FILE *Out_File;

		if (Out_File = fopen(Out_File, "wb"))
		{
			fseek(File, 0, SEEK_END);
			j = ftell(File);
			fseek(File, 0, SEEK_SET);
			for (i = 0; i < j; i++) {
				fputc(fgetc(File), Out_File);
			}

			fclose(File);
			fseek(Out_File, File_Ptr->BMP_Offset, SEEK_SET);
			
			Make_Gray(Out_File, Info_Ptr, File_Ptr);

			fclose(Out_File);
		}
		else printf("Error");

		for (i = 0; i < Info_Ptr->BMP_Height; i++) {
			free(RGB1[i]);
		}
		free(RGB1);
	}
}


