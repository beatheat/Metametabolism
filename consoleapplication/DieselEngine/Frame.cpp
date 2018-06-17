#include "Frame.h"

Frame *Frame::fm = 0;

Frame &Frame::GetInstance()
{
	if (fm == 0) fm = new Frame();
	return *fm;
}

void Frame::Release()
{
	delete fm;
}