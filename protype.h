#pragma once


void search_string(const char* string);
void change_data(const char* string);
void file_write_read(const int* a);
void data_rest();
void number_check_function(void(*file_rw)(void*), void(*file_serch)(char*), void(*file_dchnage)(char*),void(*file_drest)());