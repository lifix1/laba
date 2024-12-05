#include "file_reader.h"
#include <fstream>
#include <cstring>

int convertTimeToSeconds(const char* time_str) {
    int hours, minutes, seconds;
    sscanf(time_str, "%d:%d:%d", &hours, &minutes, &seconds);
    return hours * 3600 + minutes * 60 + seconds;
}

void read(const char* file_name, Call* array[], int& size) {
    std::ifstream file(file_name);
    if (file.is_open()) {
        size = 0;
        while (!file.eof()) {
            Call* call = new Call;

            file >> call->number;

            file >> call->date;

            char time_buffer[9];
            file >> time_buffer;
            call->time = std::string(time_buffer);

            char duration_buffer[9];
            file >> duration_buffer;
            call->duration = convertTimeToSeconds(duration_buffer);

            file >> call->tariff;

            file >> call->cost;

            array[size++] = call;
        }
        file.close();
    }
    else {
        throw "Ошибка открытия файла";
    }
}
