import argparse
import xlwt
from Bio import SeqIO
from Bio.PDB import *
import os

amino_acid_map={'ALA':'A','ARG':'R','ASN':'N','ASP':'D','CYS':'C','GLN':'Q','GLU':'E','GLY':'G','HIS':'H','ILE':'I',
                'LEU':'L','LYS':'K','MET':'M','PHE':'F','PRO':'P','SER':'S','THR':'T','TRP':'W','TYR':'Y','VAL':'V',}


if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='Input arguments')

    parser.add_argument('--pdb_name', type=str, default='')
    parser.add_argument('--pdb_path', type=str, default='')
    parser.add_argument('--chain', type=str, default='')
    parser.add_argument('--site_number', type=str, default='')
    parser.add_argument('--wt_aa', type=str, default='')
    parser.add_argument('--pH', type=float, default=7)
    parser.add_argument('--T', type=float, default=25)

    current_directory = os.getcwd()
    script_directory = os.path.dirname(os.path.abspath(__file__))
    if current_directory!=script_directory:
        print('Please cd to top folder of program!!!')
        exit(1)

    args = parser.parse_args()
    if args.pdb_name=='' or args.pdb_path=='' or args.site_number=='' or (args.site_number!='all' and args.chain=='') or ((args.site_number!='all' and args.wt_aa=='')):
        print('please check your arguments')
        exit(1)

    header=['Name','PDB_File_Path','Variation','Chain','pH','T']
    wt_list=[]
    wt_list.append(header)

    if args.site_number!='all':
        try:
            pdb_name=args.pdb_name
            pdb_path=args.pdb_path
            if not os.path.isabs(pdb_path):
                pdb_path=os.path.abspath(pdb_path)
            chain=args.chain
            assert chain!=''
            site_number=int(args.site_number)
            aa=args.wt_aa
            assert aa in amino_acid_map.values()
            pH=args.pH
            T=args.T
        except:
            print('please check your arguments')
            exit(1)

        for mut_aa in amino_acid_map.values():
            if aa != mut_aa:
                temp_list=[pdb_name,pdb_path,aa+str(site_number)+mut_aa,chain,pH,T]
                wt_list.append(temp_list)
    else:
        try:
            pdb_name=args.pdb_name
            pdb_path=args.pdb_path
            if not os.path.isabs(pdb_path):
                pdb_path=os.path.abspath(pdb_path)
            site_number=args.site_number
            assert site_number=='all'
            pH=args.pH
            T=args.T
        except:
            print('please check your arguments')
            exit(1)

        record_dict = {}
        pdb = PDBParser(QUIET=True)
        structure = pdb.get_structure(pdb_name, pdb_path)
        for chains in structure:
            for chain in chains:
                for residue in chain:
                    if residue.resname not in amino_acid_map.keys():
                        continue
                    id=residue.get_id()
                    num=id[1]
                    chain_id=chain.id
                    aa=amino_acid_map[residue.resname]
                    if chain_id not in record_dict.keys():
                        record_dict[chain_id]={}
                    record_dict[chain_id][num]=aa

        for chain in record_dict.keys():
            for num in dict(record_dict[chain]).keys():
                for mut_aa in amino_acid_map.values():
                    if record_dict[chain][num] != mut_aa:
                        temp_list = [pdb_name, pdb_path, record_dict[chain][num] + str(num) + mut_aa, chain, pH, T]
                        wt_list.append(temp_list)

    wb = xlwt.Workbook()
    ws = wb.add_sheet('sheet1')
    for i in range(len(wt_list)):
        for j in range(len(wt_list[i])):
            ws.write(i, j, wt_list[i][j])
    wb.save('./src/pred.xls')
    print('The input XLS file for prediction has already been saved in ./src/pred.xls')
    print('Next, you can use like \' python Predict_ddG_Executable.py --pred_dataset_path ./src/pred.xls --db_folder_path Your_Path/blast_db_folder/ --db_name your_db_name --if_reversed_data 0 --blast_process_num 4 --mode whole --process_num 4 \' to perform the prediction')