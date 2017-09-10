/* 
  Copyright 2017 Dennis Vesterlund

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

/*
 * File:         log.h
 * Created:      2013-02-04
 * Authors:      Dennis Vesterlund
 * License:      Apache License, see LICENSE
 * Description:  
 * Platforms:    Linux
 */

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstdarg>
#include <vector>

class log {
private:
  struct logFile {
    unsigned int verbosity;
    const char* fileName;
  };
  unsigned int verbosity;
  std::vector<logFile> logFiles;
  bool quiet;
  int countLetters( const char &letter, std::string const &searchString );
public:
  log( unsigned int v, bool q = false );
  void changeVerbosity( unsigned int v );
  int addLogfile(const char* f, unsigned int v );
  int removeLogfile(const char* f);
  void printLogFiles();
  void debugMsg( unsigned int verbosityLevel, const char* printstyle , ... );
  int logMsg( unsigned int v, const char* p, ... );
  void setQuiet(bool q);
};

















