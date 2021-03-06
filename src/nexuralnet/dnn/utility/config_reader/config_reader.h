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

#include "../../data_types/layer_settings.h"
#include "json_config_reader.h"

#ifndef NEXURALNET_UTILITY_CONFIG_READER_H
#define NEXURALNET_UTILITY_CONFIG_READER_H

namespace nexural {
	enum class ConfigReaderType {
		JSON = 0
	};

	class ConfigReader {
	public:
		static void DecodeNetCongif(const std::string& networkConfigSource, LayerSettingsCollection& layerSettingsCollection, const ConfigSourceType& configSourceType, const ConfigReaderType& readerType = ConfigReaderType::JSON);
		static void DecodeTrainerCongif(const std::string& trainerConfigPath, Params& trainerParams, Params& solverParams, const ConfigSourceType& configSourceType, const ConfigReaderType& readerType = ConfigReaderType::JSON);
	};
}
#endif
