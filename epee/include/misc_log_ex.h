// Copyright (c) 2006-2013, Andrey N. Sabelnikov, www.sabelnikov.net
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// * Neither the name of the Andrey N. Sabelnikov nor the
// names of its contributors may be used to endorse or promote products
// derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER  BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//


#ifndef _MISC_LOG_EX_H_
#define _MISC_LOG_EX_H_

#ifdef __cplusplus

#include <string>
#include <sstream>

#undef MONERO_DEFAULT_LOG_CATEGORY
#define MONERO_DEFAULT_LOG_CATEGORY "default"

#define MAX_LOG_FILE_SIZE 104850000 // 100 MB - 7600 bytes
#define MAX_LOG_FILES 50

#define MCLOG_TYPE(level, cat, color, type, x)

#define MCLOG(level, cat, color, x)
#define MCLOG_FILE(level, cat, x)

#define MCFATAL(cat,x)
#define MCERROR(cat,x)
#define MCWARNING(cat,x)
#define MCINFO(cat,x)
#define MCDEBUG(cat,x)
#define MCTRACE(cat,x)

#define MCLOG_COLOR(level,cat,color,x)
#define MCLOG_RED(level,cat,x))
#define MCLOG_GREEN(level,cat,x)
#define MCLOG_YELLOW(level,cat,x)
#define MCLOG_BLUE(level,cat,x)
#define MCLOG_MAGENTA(level,cat,x)
#define MCLOG_CYAN(level,cat,x)

#define MLOG_RED(level,x)
#define MLOG_GREEN(level,x)
#define MLOG_YELLOW(level,x)
#define MLOG_BLUE(level,x)
#define MLOG_MAGENTA(level,x)
#define MLOG_CYAN(level,x)

#define MFATAL(x)
#define MERROR(x)
#define MWARNING(x)
#define MINFO(x)
#define MDEBUG(x)
#define MTRACE(x)
#define MLOG(level,x)

#define MGINFO(x) MCINFO("global",x)
#define MGINFO_RED(x)
#define MGINFO_GREEN(x)
#define MGINFO_YELLOW(x)
#define MGINFO_BLUE(x)
#define MGINFO_MAGENTA(x)
#define MGINFO_CYAN(x)

#define IFLOG(level, cat, color, type, init, x)
#define MIDEBUG(init, x)


#define LOG_ERROR(x)
#define LOG_PRINT_L0(x)
#define LOG_PRINT_L1(x)
#define LOG_PRINT_L2(x)
#define LOG_PRINT_L3(x)
#define LOG_PRINT_L4(x)

#define _dbg3(x)
#define _dbg2(x)
#define _dbg1(x)
#define _info(x)
#define _note(x)
#define _fact(x)
#define _mark(x)
#define _warn(x)
#define _erro(x)

#define MLOG_SET_THREAD_NAME(x)

#define LOCAL_ASSERT(expr)

std::string mlog_get_default_log_path(const char *default_filename);
void mlog_configure(const std::string &filename_base, bool console, const std::size_t max_log_file_size = MAX_LOG_FILE_SIZE, const std::size_t max_log_files = MAX_LOG_FILES);
void mlog_set_categories(const char *categories);
std::string mlog_get_categories();
void mlog_set_log_level(int level);
void mlog_set_log(const char *log);

namespace epee
{
namespace debug
{
  inline bool get_set_enable_assert(bool set = false, bool v = false)
  {
    static bool e = true;
    if(set)
      e = v;
    return e;
  }
}



#define ENDL std::endl

#define TRY_ENTRY()   try {
#define CATCH_ENTRY(location, return_val) } \
  catch(const std::exception& ex) \
{ \
  (void)(ex); \
  LOG_ERROR("Exception at [" << location << "], what=" << ex.what()); \
  return return_val; \
}\
  catch(...)\
{\
  LOG_ERROR("Exception at [" << location << "], generic exception \"...\"");\
  return return_val; \
}

#define CATCH_ENTRY_L0(lacation, return_val) CATCH_ENTRY(lacation, return_val)
#define CATCH_ENTRY_L1(lacation, return_val) CATCH_ENTRY(lacation, return_val)
#define CATCH_ENTRY_L2(lacation, return_val) CATCH_ENTRY(lacation, return_val)
#define CATCH_ENTRY_L3(lacation, return_val) CATCH_ENTRY(lacation, return_val)
#define CATCH_ENTRY_L4(lacation, return_val) CATCH_ENTRY(lacation, return_val)


#define ASSERT_MES_AND_THROW(message) {LOG_ERROR(message); std::stringstream ss; ss << message; throw std::runtime_error(ss.str());}
#define CHECK_AND_ASSERT_THROW_MES(expr, message) do {if(!(expr)) ASSERT_MES_AND_THROW(message);} while(0)


#ifndef CHECK_AND_ASSERT
#define CHECK_AND_ASSERT(expr, fail_ret_val)   do{if(!(expr)){LOCAL_ASSERT(expr); return fail_ret_val;};}while(0)
#endif

#ifndef CHECK_AND_ASSERT_MES
#define CHECK_AND_ASSERT_MES(expr, fail_ret_val, message)   do{if(!(expr)) {LOG_ERROR(message); return fail_ret_val;};}while(0)
#endif

#ifndef CHECK_AND_NO_ASSERT_MES_L
#define CHECK_AND_NO_ASSERT_MES_L(expr, fail_ret_val, l, message)   do{if(!(expr)) {LOG_PRINT_L##l(message); /*LOCAL_ASSERT(expr);*/ return fail_ret_val;};}while(0)
#endif

#ifndef CHECK_AND_NO_ASSERT_MES
#define CHECK_AND_NO_ASSERT_MES(expr, fail_ret_val, message) CHECK_AND_NO_ASSERT_MES_L(expr, fail_ret_val, 0, message)
#endif

#ifndef CHECK_AND_NO_ASSERT_MES_L1
#define CHECK_AND_NO_ASSERT_MES_L1(expr, fail_ret_val, message) CHECK_AND_NO_ASSERT_MES_L(expr, fail_ret_val, 1, message)
#endif


#ifndef CHECK_AND_ASSERT_MES_NO_RET
#define CHECK_AND_ASSERT_MES_NO_RET(expr, message)   do{if(!(expr)) {LOG_ERROR(message); return;};}while(0)
#endif


#ifndef CHECK_AND_ASSERT_MES2
#define CHECK_AND_ASSERT_MES2(expr, message)   do{if(!(expr)) {LOG_ERROR(message); };}while(0)
#endif

enum console_colors
{
  console_color_default,
  console_color_white,
  console_color_red,
  console_color_green,
  console_color_blue,
  console_color_cyan,
  console_color_magenta,
  console_color_yellow
};

bool is_stdout_a_tty();
void set_console_color(int color, bool bright);
void reset_console_color();

}

extern "C"
{

#endif

#ifdef __GNUC__
#define ATTRIBUTE_PRINTF __attribute__((format(printf, 2, 3)))
#else
#define ATTRIBUTE_PRINTF
#endif

bool merror(const char *category, const char *format, ...) ATTRIBUTE_PRINTF;
bool mwarning(const char *category, const char *format, ...) ATTRIBUTE_PRINTF;
bool minfo(const char *category, const char *format, ...) ATTRIBUTE_PRINTF;
bool mdebug(const char *category, const char *format, ...) ATTRIBUTE_PRINTF;
bool mtrace(const char *category, const char *format, ...) ATTRIBUTE_PRINTF;

#ifdef __cplusplus

}

#endif

#endif //_MISC_LOG_EX_H_