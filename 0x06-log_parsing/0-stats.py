#!/usr/bin/python3
import re


class LogParsing:
    # Dictionary of code status
    CODES = {}

    # General variables
    step = 0
    total_size = 0
    status = ""
    file_size = ""

    def run(self):
        """"
        function that search the status code and size number
        """
        while True:
            try:
                line = input()

                self.parser(line)
                self.step += 1
            except (KeyboardInterrupt, EOFError):
                self.print_log_parsing()
                exit()

    def parser(self, line):
        """"
        parsing lines
        Args:
            line: input from stdin
        """
        PATTERN = '([\\d]{3})\\s([\\d]{1,4})$'
        STOP = 9

        self.status, self.file_size = re.search(PATTERN, line).group().split()

        self.total_size += int(self.file_size)

        try:
            if self.CODES[self.status]:
                self.CODES[self.status] += 1
        except KeyError:
            self.CODES[self.status] = 1

        if self.step == STOP:
            self.print_log_parsing()
            self.step = 0

    def print_log_parsing(self):
        """
        function that print parsing logs
        """
        print("File size: {}".format(self.total_size - int(self.file_size)))
        for key, value in sorted(self.CODES.items()):
            print("{}: {}".format(key, value))


if __name__ == '__main__':
    init = LogParsing()
    init.run()
