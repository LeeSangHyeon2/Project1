#pragma once

#pragma pack(push, 1)    // 1바이트 크기로 정렬
typedef struct Data2
{
    char string[10];
    short year;
    short mounth;
    short day;
}Data2, *PData2;
#pragma pack(pop)       // 정렬 설정을 이전 상태(기본값)로 되돌림



 