#include <iostream>
#include <fstream>
#include <vector>

std::string read_ascii_data(const std::string& filepath, int begin_byte, int end_byte, bool big_endian);

struct SEGYR2TextualFileHeader
{
    std::string CLIENT;
    std::string COMPANY;
    std::string CREW_NO;
    std::string LINE;
    std::string AREA;
    std::string MAP_ID;
    std::string REEL_NO;
    std::string DAY_START_OF_REEL;
    std::string YEAR;
    std::string OBSERVER;
    std::string INSTRUMENT_MFG;
    std::string INSTRUMENT_MODEL;
    std::string INSTRUMENT_SERIAL_NO;
    std::string DATA_TRACES_PER_RECORDS;
    std::string AUXILIARY_TRACES_PER_RECORDS;
    std::string CDP_FOLD;
    std::string SAMPLE_INTERVAL;
    std::string SAMPLE_PER_TRACE;
    std::string BITS_PER_IN;
    std::string BYTES_PER_SAMPLE;
    std::string RECORDING_FORMAT;
    std::string FORMAT_THIS_REEL;
    std::string MEASUREMENT_SYSTEM;
    std::string SAMPLE_CODE_FLOATING_PT;
    std::string SAMPLE_CODE_FIXED_PT;
    std::string SAMPLE_CODE_FIXED_PT_GAIN;
    std::string SAMPLE_CODE_CORRELATED;
    std::string GAIN_TYPE_FIXED;
    std::string GAIN_TYPE_BINARY;
    std::string GAIN_TYPE_FLOATING_POINT;
    std::string GAIN_TYPE_OTHER;
    std::string FILTERS_ALIAS;
    std::string FILTERS_HZ_NOTCH;
    std::string FILTERS_HZ_BAND;
    std::string FILTERS_HZ_SLOPE;
    std::string FILTERS_DB_PER_OCT;
    std::string SOURCE_TYPE;
    std::string SOURCE_NUMBER_POINTS;
    std::string SOURCE_NUMBER_POINT_INTERVAL;
    std::string SOURCE_PATTERN_LENGTH;
    std::string SOURCE_PATTERN_WIDTH;
    std::string SWEEP_START;
    std::string SWEEP_HZ_END;
    std::string SWEEP_HZ_LENGTH;
    std::string SWEEP_MS_CHANNEL_NO;
    std::string SWEEP_TYPE;
    std::string TAPER_START_LENGTH;
    std::string TAPER_MS_END_LENGTH;
    std::string TAPER_MS_TYPE;
    std::string SPREAD_OFFSET;
    std::string SPREAD_MAX_DISTANCE;
    std::string SPREAD_GROUP_INTERVAL;
    std::string GEOPHONES_PER_GROUP;
    std::string GEOPHONES_SPACING;
    std::string GEOPHONES_FREQUENCY;
    std::string GEOPHONES_MFG;
    std::string GEOPHONES_MODEL;
    std::string GEOPHONES_PATTERN;
    std::string GEOPHONES_LENGTH;
    std::string GEOPHONES_WIDTH;
    std::string TRACE_SORTED_BY_RECORD;
    std::string TRACE_SORTED_BY_CDP;
    std::string TRACE_SORTED_BY_OTHER;
    std::string AMPLITUDE_RECOVERY_NONE;
    std::string AMPLITUDE_RECOVERY_SPHERICAL_DIV;
    std::string AMPLITUDE_RECOVERY_AGC;
    std::string AMPLITUDE_RECOVERY_OTHER;
    std::string MAP_PROJECTION;
    std::string ZONE_ID;
    std::string COORDINATE_UNITS;
    /// ... PROCESSING
    std::string SEGY_REV_2_0;
    std::string END_TEXTUAL_HEADER;
};

// Represents the 400-bytes binary file header for the revision 2.0 segy standard
struct SEGYR2BinaryHeader
{
    unsigned int JOB_ID_NUMBER;                                     // BYTE 3201-3204
    unsigned int LINE_NUMBER;                                       // BYTE 3205-3208
    unsigned int REEL_NUMBER;                                       // BYTE 3209-3212
    unsigned int NB_DATA_TRACE_PER_SAMPLE;                          // BYTE 3213-3214
    unsigned int NB_AUXILIARY_TRACE_PER_SAMPLE;                     // BYTE 3215-3216
    unsigned int SAMPLE_INTERVAL;                                   // BYTE 3217-3218
    unsigned int SAMPLE_INTERVAL_ORIGINAL_FIELD_RECORD;             // BYTE 3219-3220
    unsigned int NB_SAMPLE_PER_DATA_TRACE;                          // BYTE 3221-3222
    unsigned int NB_SAMPLE_PER_DATA_TRACE_ORIGINAL_FIELD_RECORD;    // BYTE 3223-3224
    unsigned int DATA_SAMPLE_FORMAT_CODE;                           // BYTE 3225-3226
    unsigned int CMP_FOLD;                                          // BYTE 3227-3228
    unsigned int TRACE_SORTING_CODE;                                // BYTE 3229-3230
    unsigned int VERTICAL_SUM_CODE;                                 // BYTE 3231-3232
    unsigned int SWEEP_FREQUENCY_START;                             // BYTE 3233-3234
    unsigned int SWEEP_FREQUENCY_END;                               // BYTE 3235-3236
    unsigned int SWEEP_LENGTH_END;                                  // BYTE 3237-3238
    unsigned int SWEEP_TYPE_CODE;                                   // BYTE 3239-3240
    unsigned int TRACE_NUMBER_OF_SWEEP_CHANNEL;                     // BYTE 3241-3242
    unsigned int SWEEP_TRACE_TAPER_LENGTH_START;                    // BYTE 3243-3244
    unsigned int SWEEP_TRACE_TAPER_LENGTH_END;                      // BYTE 3245-3246
    unsigned int TAPER_TYPE;                                        // BYTE 3247-3248
    unsigned int CORRELATED_DATA_TRACES;                            // BYTE 3249-3250
    unsigned int BINARY_GAIN_RECOVERED;                             // BYTE 3251-3252
    unsigned int AMPLITUDE_RECOVERY_METHOD;                         // BYTE 3253-3254
    unsigned int MEASUREMENT_SYSTEM;                                // BYTE 3255-3256
    unsigned int IMPULSE_SIGNAL_POLARITY;                           // BYTE 3257-3258
    unsigned int VIBRATORY_POLARITY_CODE;                           // BYTE 3259-3260
    unsigned int EXTENDED_NB_DATA_TRACE_PER_SAMPLE;                 // BYTE 3261-3264   NON ZERO OVERRIDES 3213-3214
    unsigned int EXTENDED_NB_AUXILIARY_TRACE_PER_SAMPLE;            // BYTE 3265-3268   NON ZERO OVERRIDES 3215-3216
    unsigned int EXTENDED_NB_SAMPLE_PER_TRACE;                      // BYTE 3269-3272   NON ZERO OVERRIDES 3221-3222
    double       EXTENDED_SAMPLE_INTERVAL;                          // BYTE 3273-3280   NON ZERO OVERRIDES 3217-3218    DOUBLE PRECISION X64
    unsigned int EXTENDED_SAMPLE_INTERVAL_ORIGINAL_FIELD_RECORD;    // BYTE 3281-3288   NON ZERO OVERRIDES 3219-3220
    unsigned int EXTENDED_NB_SAMPLE_PER_TRACE_FIELD_RECORD;         // BYTE 3289-3292   NON ZERO OVERRIDES 3223-3224
    unsigned int EXTENDED_CMP_FOLD;                                 // BYTE 3293-3296   NON ZERO OVERRIDES 3227-3228
    unsigned int INTEGER_CONSTANT;                                  // BYTE 3297-3300
    unsigned int UNASSIGNED_1;                                      // BYTE 3301-3500
    unsigned int MAJOR_REV_NB;                                      // BYTE 3501                                        8  BITS UNSIGNED VALUE
    unsigned int MINOR_REV_NB;                                      // BYTE 3502                                        8  BITS UNSIGNED VALUE
    unsigned int FIXED_LENGTH_TRACE_FLAG;                           // BYTE 3503-3504
    unsigned int NB_EXTENDED_TEXTUAL_FILE_HEADER;                   // BYTE 3505-3506
    unsigned int MAX_NB_ADDITIONAL_TRACE_HEADER;                    // BYTE 3507-3510
    unsigned int TIME_BASIS_CODE;                                   // BYTE 3511-3512
    unsigned int NB_TRACE_IN_FILE;                                  // BYTE 3513-3520
    unsigned int FIRST_TRACE_BYTE_OFFSET;                           // BYTE 3521-3528
    unsigned int NB_DATA_TRAILER_STANZA_RECORD_AFTER_FIRST_TRACE;   // BYTE 3529-3532
    unsigned int NB_DATA_TRAILER_STANZA_RECORD_AFTER_FIRST_TRACE;   // BYTE 3529-3532
    unsigned int UNASSIGNED_2;                                      // BYTE 3533-3600
};

class SegyFileReader {
public:
    SegyFileReader(const std::string& filename) : filename_(filename) {}
    SegyFileReader() = delete;

    void read_file();

    const std::string get_textual_header() const { return textual_header_; }
    const std::vector<float>& get_data() const { return data_; }

    void print_textual_header() const { std::cout << textual_header_ << "\n"; }

private:
    ////////////////
    // attributes //
    ////////////////
    std::string filename_;

    std::string textual_header_ = "";
    
    std::vector<float> data_;

    SEGYR2TextualFileHeader textual_header_;
    SEGYR2BinaryHeader binary_header_;
    
    
    /////////////
    // methods //
    /////////////

    void read_textual_header(std::ifstream& file);

    void read_binary_header(std::ifstream& file);

    void extended_textual_header(std::ifstream& file);

    void read_ebcdic_header(std::ifstream& file);  

    void read_trace_headers(std::ifstream& file);

    void read_data(std::ifstream& file);
};