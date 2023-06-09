#include <segy_reader.hpp>

void SegyFileReader::read_file() {
    std::ifstream file(filename_, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file: " << filename_ << std::endl;
        return;
    }
    
    read_textual_header(file);
    read_ebcdic_header(file);
    read_binary_header(file);
    read_trace_headers(file);
    read_data(file);

    file.close();
}

std::string SegyFileReader::read_ascii_data(const std::string& filepath, int begin_byte, int end_byte, bool big_endian)
{
    // ASCII (American Standard Code for Information Interchange) is a character encoding scheme
    // Each character is represented by a 7-bit binary value, allowing a total of 128 unique characters to be encoded
    // The character set includes alphabetic characters (uppercase and lowercase), digits, punctuation marks, 
    //  control characters (such as newline and carriage return), and special symbols

    // Wikipedia https://en.wikipedia.org/wiki/ASCII

    std::ifstream file(filepath, std::ios::binary);
    if (!file)
    {
        std::cerr << "> Error opening file: " << filepath << std::endl;
        return "";
    }

    // Calculate the number of characters to read
    int num_chars = end_byte - begin_byte + 1;
    if (num_chars <= 0)
    {
        std::cerr << "> Invalid byte range" << std::endl;
        return "";
    }

    // Adjust the byte order if using big endian
    if (big_endian)
    {
        begin_byte = (begin_byte << 8) | (begin_byte >> 8);
        end_byte = (end_byte << 8) | (end_byte >> 8);
    }

    // Seek to the beginning byte
    file.seekg(begin_byte, std::ios::beg);

    // Read the ASCII data
    char* data = new char[num_chars];
    file.read(data, num_chars);

    // Create a string from the data
    std::string ascii_data(data, num_chars);

    delete[] data;
    file.close();

    return ascii_data;
}

void SegyFileReader::read_textual_header(std::ifstream& file)
{
    // this part is located at the begining of the file
    // ACSII
    // 3200 bytes
    // 40 lines of 80 characters

    textual_header_ = read_ascii_data(filename_, 0, 3200, true);
}

void SegyFileReader::read_binary_header(std::ifstream& file)
{
    // second header of the file
    // binary
    // 400 bytes
}

void SegyFileReader::extended_textual_header(std::ifstream& file)
{
    // optional extended part of the textual header
    // ASCII
    // n * 3200 bytes, n can be zero or greater
    // the value of n is indicated in the binary file header (bytes 3505-3506)

}

void SegyFileReader::read_ebcdic_header(std::ifstream& file)
{

}



void SegyFileReader::read_trace_headers(std::ifstream& file)
{
    // each trace has a trace header
    // 240 bytes
}

void SegyFileReader::read_data(std::ifstream& file)
{
    // each trace has somne data
    // data is typed float32
}