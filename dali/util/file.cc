// Copyright (c) 2017-2018, NVIDIA CORPORATION. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <string>

#include "dali/util/file.h"
#include "dali/util/local_file.h"

namespace dali {

std::unique_ptr<FileStream> FileStream::Open(const std::string& uri, bool read_ahead) {
  if (uri.find("file://") == 0) {
    return std::unique_ptr<FileStream>(
            new LocalFileStream(uri.substr(std::string("file://").size()), read_ahead));
  } else {
    return std::unique_ptr<FileStream>(new LocalFileStream(uri, read_ahead));
  }
}

bool FileStream::ReserveFileMappings(unsigned int num) {
  return LocalFileStream::ReserveFileMappings(num);
}
void FileStream::FreeFileMappings(unsigned int num) {
  LocalFileStream::FreeFileMappings(num);
}

}  // namespace dali
