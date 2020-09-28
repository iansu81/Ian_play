# Function to parse QRS signal
# offset 4 bit and & with 0b00001111
def parse_QRS(data_byte):
    QRS = ( (data_byte >> 4) & 0xF)

    return QRS

if __name__ == '__main__':

    # The filename we want to parse
    target_file = 'test.txt'

    # Numbers of qrs signal
    num_qrs = 0

    # Sum of qrs signal
    total_qrs = 0


    with open(target_file) as log:
        data = log.readlines()
        for line in data:
            singla_byte_list = line.split()

            # Only pick the identifier "01"
            if singla_byte_list[1] == '01':
                num_qrs += 1

                # Pick the 4th byte in the data row, but it has one more byte for timestamp in the very beginning
                bytes_3 = int(singla_byte_list[4], 16)
                total_qrs += parse_QRS(bytes_3)

    print("ANS: ", total_qrs/num_qrs)