#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 4096
#define LEN 50
#define LINE_LEN 500

int string_len(char *s) // find string length
{
    int i = 0;
    while (*s != '\0')
    {
        i++;
        s++;
    }
    int count = i;
    return count;
}

int string_n_cmp(char* w1, char* w2, int len) { // compare string with given length
    if (string_len(w1) < len || string_len(w2) < len)
    {
        return -1; // error checking
    }
    int i = 0;
    while (i < len)
    {
        if (w1[i] != w2[i])
        {
            return -1;
        }
        i++;
    }
    return 0; // if equals
}

int find_min(int* array, unsigned int len) { // find min in the array
	int min = array[0];
	for (int i = 0; i < len; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

int two_colon(char* string) // check if two colons
{
    if (*(string + 1) != ':')
    {
        return -1; // only one colon
    }
    if (*(string + 1) == ':' && *(string + 2) == ':')
    {
        return -1; // more than two colons
    }
    return 1;
}

int colon_index(char* str) // return first colon_idx of the given string
{
    int i = 0;
    while (str[i] != '\0')
    {
        if(str[i] == ':')
        {
            return i;
        }
        i++;
    }
    return -1; // if not found
}
int check_args(char* s, int len) // source and destination cannot contain digits
{
    for (int i = 0; i < len; i++)
    {
        if (s[i] == ':') // ':' is the separator, and cannot be valid in the source/ destination
        {
            return -1;
        }
    }
    return 1;
}
void test_args()
{
    // char* myargs ="Coffs";
    // char* myargs = "";
    // char* myargs = " Coffs";
    // char* myargs = "1Coffs";
    char* myargs = "Cof:fs";
    int ret = check_args(myargs, 5);
    printf("ret is %d\n", ret);

}
int check_valid_src_or_des(char* s, int idx) // check if source or destination is valid
{
    if(s[0] == ':' || s[0] == '\0') // could start with digit or space
    {
        return -1;
    }
    if (two_colon(s + idx) == -1) // colon index found, not two colons
    {
        return -1;
    }
    return 1;
}

void test_valid_src_or_des()
{
    // ----check valid source----
    // char* src = "Coffs Harbour::Morisset::19:09:14"; // expect 1
    // char* src = " ::Morisset::19:09:14";
    // char* src = "1Coffs::Melbourne::08:23:33";
    // char* src = " Coffs::Melbourne::08:23:33";
    // char* src = "";

    // exptect -1: not two colons
    // char* src = "Cof:fs:Melbourne::08:23:33";
    // char* src = "Coffs::::Melbourne::08:23:33";
    char* src = "Coffs";

    int idx_s = colon_index(src);
    int res_s = check_valid_src_or_des(src, idx_s);
    printf("res = %d\n", res_s); // expect 1

    // ----check valid destination----
    char* des = "Melbourne::08:23:33";
    int idx_d = colon_index(des);
    int res = check_valid_src_or_des(des, idx_d);
    printf("res = %d\n", res); // expect 1
}

int check_valid_time(char* s)
{
    int hour, minute, second;
    if (sscanf(s, "%d:%d:%d", &hour, &minute, &second) != 3) // not separated with ':', not digit, not three parameters, or parameter len is not two
    {
        return -1;
    }
    // "09:13:15"
    int idx = colon_index(s);
    int idx2 = colon_index(s + 1+ idx);
    if (idx != 2 || idx2 != 2) // if the hour / minute length is not 2
    {
        return -1;
    }
    char* str = s + idx + idx2 + 4;
    if (str[0] != '\n' && str[0] != '\0') // if the second length is not 2
    {
        return -1;
    }
    if (hour >= 24 || minute >= 60 || second >= 60)
    {
        return -1;
    }
    return 1;
}
void test_valid_time()
{
    char* time = "20:01:14";
    printf(" len is %d\n", string_len(time));
    int ret = check_valid_time(time);
    printf("ret is %d\n", ret);
}

int is_valid(char* s)
{
    int src_idx = colon_index(s); // check source
    if (src_idx == -1)
    {
        return -1;
    }
    if (check_valid_src_or_des(s, src_idx) == -1)
    {
        return -1;
    }

    char* s_des = s + src_idx + 2; // check destination
    int des_idx = colon_index(s_des);
    if (des_idx == -1)
    {
        return -1;
    }

    if (check_valid_src_or_des(s_des, des_idx) == -1)
    {
        return -1;
    }
    // source::des::hour:minute:second
    char* time = s_des + des_idx + 2; // check time
    if (check_valid_time(time) == -1)
    {
        return -1;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    if (argc < 4) // check args length
    {
        printf("Please provide <source> <destination> <time> as command line arguments\n");
        exit(0);
    }
    char* src = argv[1];
    char* des = argv[2];
    char* time = argv[3];
    int src_len = string_len(src);
    int des_len = string_len(des);

    if (check_args(src, src_len) == -1 || check_args(des, des_len) == -1 || check_valid_time(time) == -1)
    {
        printf("Invalid args\n");
        exit(0);
    }

    char BUF[MAX_LEN];
    int hour, minute, second;
    int next_hour, next_minute, next_sec;
    int i = 0;
    int data_num = 0;
    int res[LINE_LEN];
    while(fgets(BUF, MAX_LEN, stdin)) // not read the whole file at once
    {
        int ret = is_valid(BUF);
        // printf("%d\n", ret);

        if (ret == -1) {
            continue;
        } // invalid - skip the line
        if (*(BUF + MAX_LEN - 1) != '\0') // lines greater than max
        {
            printf(" Lines larger than the maximum limit\n");
            exit(0);
        }
        data_num++;
        if (string_n_cmp(BUF, src, src_len) == 0 && string_n_cmp(BUF + src_len + 2, des, des_len) == 0) // same src & des
        {
            // printf("same\n");
            if (sscanf(BUF + src_len + des_len + 4, "%d:%d:%d", &hour, &minute, &second) == 3)
            {
                if (i == 0) // the next day's first avaliable train with target des & src
                {
                    next_hour = hour;
                    next_minute = minute;
                    next_sec = second;
                }
                res[i] = 10000 * hour + 100 * minute + second;
                // printf("result = %d\n", res[i]);
                i++;
            }
        }
    }
    int count = i;
    // printf("count = %d\n", count);

    if (data_num != 0 && count == 0) // not find with target source & destination
    {
        printf("No suitable trains can be found\n");
        exit(0);
    }
    if (data_num == 0)
    {
        printf("No timetable to process\n");
        exit(0);
    }

    int input_h, input_m, input_s;
    sscanf(time, "%d:%d:%d", &input_h, &input_m, &input_s);
    // printf("%d %d %d\n", input_h, input_m, input_s);
    int input_time = 10000 * input_h + 100 * input_m + input_s;
    // printf("%d\n", input_time);

    // time - unsorted: find the greater time
    int arr[LEN] = {0};
    int num = 0;
    for (int i = 0; i < count; i++)
    {
        if (res[i] >= input_time) // accept the case that arrive at the exact time
        {
            arr[num] = res[i];
            num++;
        }
    }
    if (num == 0) // no time is greater than the target time
    {
        printf("The next train to %s from %s departs at %02d:%02d:%02d\n", des, src, next_hour, next_minute, next_sec);
        exit(0);
    }
    int time_min = find_min(arr, num);
    // printf("%d\n", time_min);
    int my_hour = time_min / 10000;
    int my_minute = (time_min - 10000 * my_hour) / 100;
    int my_sec = time_min - 10000 * my_hour - 100 * my_minute;
    // printf("my_hour is %d\n", my_hour);

    printf("The next train to %s from %s departs at %02d:%02d:%02d\n", des, src, my_hour, my_minute, my_sec);
}
