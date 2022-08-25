#!/bin/bash

# Trigger all your test cases with this script
cat tests/unsorted_time.in | xargs -a tests/unsorted_time.args ./timetable | diff - tests/unsorted_time.out

cat tests/single_station1.in | xargs -a tests/single_station1.args ./timetable | diff - tests/single_station1.out

cat tests/multiple_station1.in | xargs -a tests/multiple_station1.args ./timetable | diff - tests/multiple_station1.out

cat tests/missing_station1.in | xargs -a tests/missing_station1.args ./timetable | diff - tests/missing_station1.out

cat tests/no_enough_args.in | xargs -a tests/no_enough_args.args ./timetable | diff - tests/no_enough_args.out

cat tests/invalid_args_time1.in | xargs -a tests/invalid_args_time1.args ./timetable | diff - tests/invalid_args_time1.out

cat tests/invalid_args_time2.in | xargs -a tests/invalid_args_time2.args ./timetable | diff - tests/invalid_args_time2.out

cat tests/invalid_args_time3.in | xargs -a tests/invalid_args_time3.args ./timetable | diff - tests/invalid_args_time3.out

cat tests/invalid_args_time4.in | xargs -a tests/invalid_args_time4.args ./timetable | diff - tests/invalid_args_time4.out

cat tests/invalid_args_time5.in | xargs -a tests/invalid_args_time5.args ./timetable | diff - tests/invalid_args_time5.out

cat tests/invalid_args_time6.in | xargs -a tests/invalid_args_time6.args ./timetable | diff - tests/invalid_args_time6.out

cat tests/invalid_args_time7.in | xargs -a tests/invalid_args_time7.args ./timetable | diff - tests/invalid_args_time7.out

cat tests/input_src_invalid1.in | xargs -a tests/input_src_invalid1.args ./timetable | diff - tests/input_src_invalid1.out

cat tests/input_src_invalid2.in | xargs -a tests/input_src_invalid2.args ./timetable | diff - tests/input_src_invalid2.out

cat tests/input_des_invalid1.in | xargs -a tests/input_des_invalid1.args ./timetable | diff - tests/input_des_invalid1.out

cat tests/input_des_invalid2.in | xargs -a tests/input_des_invalid2.args ./timetable | diff - tests/input_des_invalid2.out

cat tests/input_time_valid1.in | xargs -a tests/input_time_valid1.args ./timetable | diff - tests/input_time_valid1.out

cat tests/input_time_valid2.in | xargs -a tests/input_time_valid2.args ./timetable | diff - tests/input_time_valid2.out

cat tests/input_time_valid3.in | xargs -a tests/input_time_valid3.args ./timetable | diff - tests/input_time_valid3.out

cat tests/input_time_valid4.in | xargs -a tests/input_time_valid4.args ./timetable | diff - tests/input_time_valid4.out

cat tests/input_time_valid5.in | xargs -a tests/input_time_valid5.args ./timetable | diff - tests/input_time_valid5.out

cat tests/next_day_train.in | xargs -a tests/next_day_train.args ./timetable | diff - tests/next_day_train.out
