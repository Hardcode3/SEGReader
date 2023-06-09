#include <iostream>
#include <fstream>
#include <vector>


class SegyFileReader {
public:
    SegyFileReader(const std::string& filename) : filename_(filename) {}

    void read_file();

    const std::string get_textual_header() const { return textual_header_; }
    const std::vector<float>& get_data() const { return data_; }

    void print_textual_header() const { std::cout << textual_header_ << "\n"; }

private:
    ////////////////
    // attributes //
    ////////////////
    std::string filename_;

    struct BinaryHeader {
        short sample_interval;
        int trace_count;
    } header;

    std::string textual_header_ = "";
    std::vector<float> data_;
    
    
    /////////////
    // methods //
    /////////////
    
    std::string read_ascii_data(const std::string& filepath, int begin_byte, int end_byte, bool big_endian);

    void read_textual_header(std::ifstream& file);

    void read_binary_header(std::ifstream& file);

    void extended_textual_header(std::ifstream& file);

    void read_ebcdic_header(std::ifstream& file);  

    void read_trace_headers(std::ifstream& file);

    void read_data(std::ifstream& file);
};