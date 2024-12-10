#include "file_reader.h"
#include <fstream>
#include <cstring>

int convertTimeToSeconds(const char* time_str) {
    int hours, minutes, seconds;
    if (sscanf_s(time_str, "%d:%d:%d", &hours, &minutes, &seconds) != 3) {
        throw "������: �������� ������ �������!";
    }
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

            char time_buffer[16];
            file >> time_buffer;
            if (strlen(time_buffer) >= sizeof(time_buffer)) {
                throw "������: ����� ��������� ���������� �����!";
            }
            call->time = std::string(time_buffer);

            char duration_buffer[16]; 
            file >> duration_buffer;
            if (strlen(duration_buffer) >= sizeof(duration_buffer)) {
                throw "������: ������������ ������ ��������� ���������� �����!";
            }
            call->duration = convertTimeToSeconds(duration_buffer);

            file >> call->tariff;

            file >> call->cost;

            if (file.fail()) {
                delete call; 
                throw "������: �������� ������ ������ � �����!";
            }

            array[size++] = call;

            if (size >= 100) { 
                throw "������: �������� ������ �������!";
            }
        }
        file.close();
    }
    else {
        throw "������ �������� �����";
    }
}
