/* Copyright (C) 2016-2017 Alexandru-Valentin Musat (alexandruvalentinmusat@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "converter.h"
#include <opencv2/core/core.hpp>

namespace nexural {
	namespace converter {
		void CvtMatToTensor(const cv::Mat& inputImage, Tensor& outputData) {
			outputData.Resize(1, inputImage.channels(), inputImage.rows, inputImage.cols);

			if (inputImage.channels() == 1) {
				for (long nr = 0; nr < outputData.GetNR(); nr++)
				{
					for (long nc = 0; nc < outputData.GetNC(); nc++)
					{
						for (long k = 0; k < outputData.GetK(); k++) {
							float_n value = (float_n)inputImage.at<uchar>(nr, nc);
							outputData[(k * outputData.GetNR() + nr) * outputData.GetNC() + nc] = value;
						}
					}
				}
			}
			else if (inputImage.channels() == 3)
			{
				for (long nr = 0; nr < outputData.GetNR(); nr++)
				{
					for (long nc = 0; nc < outputData.GetNC(); nc++)
					{
						cv::Vec3b intensity = inputImage.at<cv::Vec3b>(nr, nc);
						for (long k = 0; k < outputData.GetK(); k++) {
							float_n value = (float_n)intensity.val[k];
							outputData[(k * outputData.GetNR() + nr) * outputData.GetNC() + nc] = value;
						}
					}
				}
			}
		}

		void CvtVecOfMatToTensor(const std::vector<cv::Mat>& inputImages, Tensor& outputData) {
			if (inputImages.size() == 0) {
				return;
			}

			long numSamples = static_cast<long>(inputImages.size());
			long channels = static_cast<long>(inputImages[0].channels());
			long nr = inputImages[0].rows;
			long nc = inputImages[0].cols;

			outputData.Resize(numSamples, channels, nr, nc);

			for (long imageNumber = 0; imageNumber < numSamples; imageNumber++) {
				int currentChannels = inputImages[0].channels();
				long currentNr = inputImages[0].rows;
				long currentNc = inputImages[0].cols;

				if (currentChannels != channels || currentNr != nr || currentNc != nc) {
					throw std::runtime_error("All the samples inside a tensor shoud have the same size!");
				}

				for (long nr = 0; nr < outputData.GetNR(); nr++)
				{
					for (long nc = 0; nc < outputData.GetNC(); nc++)
					{
						cv::Vec3b intensity = inputImages[imageNumber].at<cv::Vec3b>(nr, nc);
						for (long k = 0; k < outputData.GetK(); k++) {
							float_n col = (float_n)intensity.val[k];
							outputData[(k * outputData.GetNR() + nr) * outputData.GetNC() + nc] = col;
						}
					}
				}
			}
		}

		void CvtTensorToMat(const Tensor& inputData, cv::Mat& outputImage) {

		}

		void CvtTensorToVecOfMat(const Tensor& inputData, std::vector<cv::Mat>& outputImages) {
			outputImages.clear();

			long kTotal = inputData.GetK();
			long ncTotal = inputData.GetNC();
			long nrTotal = inputData.GetNR();

			for (long numSamples = 0; numSamples < inputData.GetNumSamples(); numSamples++) {
				if (kTotal == 1) {
					cv::Mat tempImage(cv::Size(ncTotal, nrTotal), CV_8UC1);
					for (long nr = 0; nr < nrTotal; nr++) {
						for (long nc = 0; nc < ncTotal; nc++) {
							tempImage.at<uchar>(nr, nc) = (uchar)inputData[((numSamples*inputData.GetK())*inputData.GetNR() + nr)*inputData.GetNC() + nc];
						}
					}
					outputImages.push_back(tempImage);
				}
				else if (kTotal == 3) {
					cv::Mat tempImage(cv::Size(ncTotal, nrTotal), CV_8U);
					for (long nr = 0; nr < nrTotal; nr++) {
						for (long nc = 0; nc < ncTotal; nc++) {
							for (long k = 0; k < kTotal; k++) {
								tempImage.at<uchar>(nr, nc) = (uchar)inputData[((numSamples*inputData.GetK() + k)*inputData.GetNR() + nr)*inputData.GetNC() + nc];
							}
						}
					}
					outputImages.push_back(tempImage);
				}
			}
		}
	}
}
