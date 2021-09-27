# def buildLoL(f):
#     fields = f.readline().strip().split(',')
#     lol = [[]]
#     for line in f:
#         lol.append(line.strip().split(','))
#     return fields, lol


# def buildLoD(f):
#     fields = f.readline().strip().split(',')
#     LoD = []
#     for line in f:
#         D = {}
#         for i in range(len(fields)):
#             D[fields[i]] = line.strip().split()[i]
#             LoD.append(D)
#     return fields, LoD

from pprint import pprint


def buildDoL(f):
    """build a dictionary of list from an input file

    Args:
            f (file): input csv file that has been read

    Returns:
            fields: list of fields in the input file
            DoL: dictionary of list that stores in put file, with keys are the fields in input file.
    """
    DoL = {}
    fields = f.readline().strip().split(',')
    for field in fields:
        DoL[field] = []
    for line in f:
        for i in range(len(fields)):
            value = line.strip().split(',')[i]
            DoL[fields[i]].append(value)
    return fields, DoL


def DoLtoLoD(DoL):
    """translate a dictionary of list into a list of dictionaries

    Args:
        DoL (Dictionary of List): input Disctionary of List

    Returns:
        List of Dictionary: the output list of dictionaries, where each dictionary represent a row, where its keys are fields.
    """
    LoD = []
    fields = list(DoL.keys())
       for i in range(len(DoL[fields[0]])):
            D = {}
            for field in fields:
                D[field] = DoL[field][i]
                LoD.append(D)
        return fields, LoD


def main():
    filename = "topnames.csv"
    f = open(filename, 'r')
    fields, DoL = buildDoL(f)
    # print(fields)
    # print(DoL)
    fields, LoD = DoLtoLoD(DoL)
    pprint(LoD)
    # print(fields)


main()
