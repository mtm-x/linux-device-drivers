def main():

    driver_file = open('/proc/lotus_driver', 'r')
    kernel_msg_to_user = driver_file.readline()
    print(kernel_msg_to_user)
    driver_file.close()
    return

main()