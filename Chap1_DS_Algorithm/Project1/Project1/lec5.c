#include <stdio.h>

// 함수 선언
int is_valid_date(int year, int month, int day);

int main() {
    int T;
    printf("테스트 케이스의 개수를 입력하세요: ");
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int year, month, day;
        printf("테스트 케이스 #%d\n", t);
        printf("연월일을 입력하세요 (YYYYMMDD): ");
        scanf("%d", &year);

        // 입력 받은 연월일을 각각의 변수에 저장
        month = (year % 10000) / 100;
        day = year % 100;
        year /= 10000;

        if (is_valid_date(year, month, day)) {
            printf("#%d %04d/%02d/%02d\n", t, year, month, day);
        }
        else {
            printf("#%d -1\n", t);
        }
    }

    return 0;
}

// 날짜의 유효성을 판단하는 함수
int is_valid_date(int year, int month, int day) {
    if (month < 1 || month > 12) {
        return 0; // 월이 유효하지 않은 경우
    }
    if (day < 1 || day > 31) {
        return 0; // 일이 유효하지 않은 경우
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return 0; // 해당 월에 30일 이상인 경우
    }
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                return 0; // 윤년인데 29일 이상인 경우
            }
        }
        else {
            if (day > 28) {
                return 0; // 윤년이 아니고 28일 이상인 경우
            }
        }
    }
    return 1; // 모든 조건을 만족하는 경우 유효한 날짜
}