#include "Texture2D.h"
#include <iostream>
#include <fstream>
#include <string>


Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &_ID);
}

bool Texture2D::Load(char* path, int width, int height)
{
	char* tempTextureData;
	int fileSize;
	std::ifstream inFile;

	_width = width;
	_height = height;

	inFile.open(path, std::ios::binary);

	if (!inFile.good())
	{
		std::cout << "Failed to open texture file!" << std::endl;
		return false;
	}

	//seeks to end of the file, finds the size of the file, creates an array of the file size, seeks back to the beggining, then reads in the data
	inFile.seekg(0, std::ios::end);
	fileSize = (int)inFile.tellg();
	tempTextureData = new char[fileSize];
	inFile.seekg(0, std::ios::beg);
	inFile.read(tempTextureData, fileSize);
	inFile.close();

	std::cout << path << " Loaded." << std::endl;


	//get next tex ID, Bind the tex to the id, specifiying the details.
	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	delete[] tempTextureData;
	return true;

}

