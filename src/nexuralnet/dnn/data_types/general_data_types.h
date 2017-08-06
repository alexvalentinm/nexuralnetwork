/* Copyright (C) 2017 Alexandru-Valentin Musat (contact@nexuralsoftware.com)

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

#include <map>

#ifndef NEXURALNET_DATA_TYPES_GENERAL_DATA_TYPES_H
#define NEXURALNET_DATA_TYPES_GENERAL_DATA_TYPES_H

namespace nexural {
	typedef double float_n;

	typedef std::map<std::string, std::string> Params;

	enum class NetworkResultType
	{
		UNKNOWN = 0,
		REGRESSION = 1,
		BINARY_CLASSIFICATION = 2,
		MULTICLASS_CLASSIFICATION = 3,
		DETECTION = 4
	};

	enum class NetworkState {
		RUN = 0,
		TRAINING = 1,
		VALIDATION = 2
	};

	enum class ConfigSourceType {
		FROM_FILE = 0,
		FROM_STRING = 1
	};

	enum class ImageExtension
	{
		JPG = 0,
		JPEG = 1,
		PNG = 2,
		BMP = 3
	};
}
#endif
