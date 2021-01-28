#!/usr/bin/python3
""" Class LogParsing """

import re


def print_log_parsing(CODES, file_size):
    """
    function that print parsing logs
    args:
        codes: is a dictionary of status code
        file_size: is the size of status
    """
    print("File size: {}".format(file_size))
    for key, value in sorted(CODES.items()):
        print("{}: {}".format(key, value))


def run():
    """"
    function that search the status code and size number
    """
    PATTERN = '([\\d]{3})\\s([\\d]{1,4})$'
    CODES = {}
    STOP = 10
    step = 1
    size = 0

    while True:
        try:

            line = input()

            status, file_size = re.search(PATTERN, line).group().split()

            try:
                if CODES[status]:
                    CODES[status] += 1
            except KeyError:
                CODES[status] = 1

            size += int(file_size)

            if step == STOP:
                print_log_parsing(CODES, size)
                step = 1

            step += 1

        except (KeyboardInterrupt, EOFError):
            print_log_parsing(CODES, size)
            exit()


if __name__ == '__main__':
    run()