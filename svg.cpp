#include "lab03.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
using namespace std;

 void svg_begin(double width, double height)
  {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
  }
void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='"<<left<<"' y='"<<baseline<<"'>"<<text<<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
  cout<<"<rect x='"<<x<<"' y='"<<y<<"' width='"<<width<<"' height='"<<height<<"' stroke='"<<stroke<<"' fill='"<<fill<<"' />";
}

string make_info_text(){
    stringstream buffer;
    DWORD dwVersion = 0;
    dwVersion = GetVersion();
    DWORD info = GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD version = info & mask;
    printf("Windows decimal-version is %u\n", version);
    printf("Windows 16x version : %x\n", version);
    if ((info & 0x80000000) == 0) {
    DWORD platform = info >>16;
    DWORD mask_major = 0x000000ff;
    DWORD version_major = version & mask_major;
    DWORD version_minor = version >> 8;
    DWORD build = platform;
    printf("Windows major version is : %x\n", version_major);
    printf("Windows minor version is : %x\n", version_minor);
     printf("Version is %d.%d (%d)\n",
               version_major,
               version_minor,
                build);
  char system_dir[MAX_PATH];
  char comp_name [MAX_COMPUTERNAME_LENGTH+1];
  DWORD size = sizeof(comp_name);
  GetComputerNameA(comp_name, &size);

  buffer <<"Computer name:"<< comp_name;
}

    // TODO: получить версию системы, записать в буфер.
    // TODO: получить имя компьютера, записать в буфер.
    return buffer.str();
}
