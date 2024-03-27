#include <stdio.h>

// �Լ� ����
int is_valid_date(int year, int month, int day);

int main() {
    int T;
    printf("�׽�Ʈ ���̽��� ������ �Է��ϼ���: ");
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int year, month, day;
        printf("�׽�Ʈ ���̽� #%d\n", t);
        printf("�������� �Է��ϼ��� (YYYYMMDD): ");
        scanf("%d", &year);

        // �Է� ���� �������� ������ ������ ����
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

// ��¥�� ��ȿ���� �Ǵ��ϴ� �Լ�
int is_valid_date(int year, int month, int day) {
    if (month < 1 || month > 12) {
        return 0; // ���� ��ȿ���� ���� ���
    }
    if (day < 1 || day > 31) {
        return 0; // ���� ��ȿ���� ���� ���
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return 0; // �ش� ���� 30�� �̻��� ���
    }
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                return 0; // �����ε� 29�� �̻��� ���
            }
        }
        else {
            if (day > 28) {
                return 0; // ������ �ƴϰ� 28�� �̻��� ���
            }
        }
    }
    return 1; // ��� ������ �����ϴ� ��� ��ȿ�� ��¥
}