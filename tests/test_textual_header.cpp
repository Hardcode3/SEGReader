#include <segy_reader.hpp>


int main()
{
    SegyFileReader segy_reader("C:\\Users\\Baptiste\\projects\\SEGYReader\\tests\\F3_entire.sgy");
    //SegyFileReader segy_reader("C:\\Users\\Baptiste\\projects\\SEGYReader\\tests\\2d_land_vibroseis_seismic.sgy");
    segy_reader.read_file();
    segy_reader.print_textual_header();
    return 0;
}