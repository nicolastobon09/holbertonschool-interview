#!/usr/bin/python3
""" Class LogParsing """

import re


def parser(line):
    """"
    parsing lines
    Args:
        line: input from stdin
        return: status code and size
    """
    status = ""
    file_size = ""

    PATTERN = '([\\d]{3})\\s([\\d]{1,4})$'
    status, file_size = re.search(PATTERN, line).group().split()

    print(file_size)

    return (status, file_size)


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
    CODES = {}
    step = 0
    size = 0
    STOP = 9

    while True:
        try:

            line = input()

            status, file_size = parser(line)

            try:
                if CODES[status]:
                    CODES[status] += 1
            except KeyError:
                CODES[status] = 1

            size += int(file_size)

            if step == STOP:
                print_log_parsing(CODES, size)
                step = 0

            step += 1

        except (KeyboardInterrupt, EOFError):
            print_log_parsing(CODES, size)
            exit()


if __name__ == '__main__':
    run()
