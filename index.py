import os
import sys


def get_all_children_file_name(root_path, f, level, flag):
    """
    :param root_path:
    :param f:
    :param level:
    :param flag: 是否输出隐藏的文件，默认隐藏
    :return:
    """
    for path in os.listdir(root_path):
        if path.startswith(".") and flag:
            continue
        f.writelines(f"{'|   '*level}"+"|--"+path+"\n")
        curr_path = os.path.join(root_path, path)
        if os.path.isdir(curr_path):
            get_all_children_file_name(curr_path, f, level+1, flag)


if __name__ == '__main__':
    root_path = os.getcwd()
    flag = int(sys.argv[-1]) if len(sys.argv) > 2 else 1
    with open(os.path.join(root_path, "index.txt"), "w", encoding='utf-8') as f:
        f.writelines(".\n")
        get_all_children_file_name(root_path, f, level=0, flag=flag)