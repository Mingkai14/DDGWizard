.. _Predict ΔΔG:

.. raw:: html

    <style>.highlight {
            background-color: #E7FC9F;
            color: #000000;
            padding: 6px;
            font-size: 12px;
            font-weight: 100;
        }
            .keyword-highlight {
            background-color: #FFFFF0;
            color: #FF3366;
            padding: 6px;
            font-size: 12px;
            font-weight: 100;
        }
    </style>

Predict ΔΔG
===========

.. raw:: html

    <div style="text-align: justify;">
    This guide is intended to show users how to use DDGWizard to predict ΔΔG.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>1. Prepare a Blast database</h4>
    <p>A Blast database is required for the program to run. The program will use the path to the Blast database to invoke it and perform sequence alignment.</p>
    <p></p>
    To construct a Blast database, you first need to prepare a fasta file of the protein sequence database.
    <p></p>
    The richness of the sequence database will significantly impact the accuracy of the predictions. You can use your own fasta database file, but we recommend downloading it from <a href="https://ftp.uniprot.org/pub/databases/uniprot/uniref/">the Uniref</a>.
    <p></p>
    Our program was tested using <a href="https://ftp.uniprot.org/pub/databases/uniprot/uniref/uniref50/">the Uniref50 database</a>.
    <p></p>
    Once you finish downloading, you need to unzip it (taking Uniref50 as an example):
    </div>

.. code-block::

    $ gzip -d uniref50.fasta.gz

.. raw:: html

    <div style="text-align: justify;">
    You can obtain a fasta file. Then you need to use Blast suite to create a Blast database using obtained fasta file.
    <p></p>
    There is an existing blast+ 2.13.0 program folder in our program. Please use the command as follows:
    <p></p>
    </div>

.. raw:: html

    <div class="highlight-default notranslate">
    <div class="highlight">
    <pre style="overflow: scroll">
    $ cd DDGWizard/bin/ncbi_blast_2_13_0+/bin/
    $ ./makeblastdb -in <b>&lt;the path to fasta file&gt;</b> -dbtype prot -out <b>&lt;the path to save Blast database&gt;</b>/<b>&lt;the name to assign for Blast database&gt;</b> -parse_seqids
    </pre>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    This step will take some time, depending on the size of the database file and the performance of your computer system.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>2. Example template</h4>
    <p>We first provide you with an example template of running DDGWizard to predict ΔΔG, and then explain the specifics of each parameter in detail.</p>
    <p></p>
    You can run the program with:
    <p></p>
    <div>

.. raw:: html

    <div class="highlight-default notranslate">
    <div class="highlight">
    <pre style="overflow: scroll">
    $ conda activate DDGWizard
    $ cd DDGWizard/
    $ python Predict_ddG_Executable.py \
        --pred_dataset_path <b>&lt;the path to xls file of raw data&gt;</b> \
        --db_folder_path <b>&lt;the path to save Blast database&gt;</b> \
        --db_name <b>&lt;the name to assign for Blast database&gt;</b> \
        --if_reversed_data 0 \
        --blast_process_num 4 \
        --mode whole \
        --process_num 4
    </pre>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>3. Parameter details</h4>
    Below are the details of the parameters for the ΔΔG prediction program:
    <p></p>
    (1). <span class="keyword-highlight">--pred_dataset_path</span>
    <p></p>
    This parameter indicates that you need to provide the path to an <span class="keyword-highlight">xls</span> file, which contains the raw data you want to use for predicting ΔΔG.
    <p></p>
    In the path <span class="keyword-highlight">DDGWizard/src</span>, there is a sample file <span class="keyword-highlight">sample_pred.xls</span> that you can use directly for testing and as a reference.
    <p></p>
    We list some of the contents of this file here, and provide detailed descriptions of each column's attributes in the table file:
    <p></p>
    <div>

+-------------+---------------------+------------------+----------------+----------+------------------+
| Name        | PDB_File_Path       | Variation        | Chain          |   pH     |  T               |
+=============+=====================+==================+================+==========+==================+
| 1SHG        | ./src/pdbs/1shg.pdb | Y57H             |   A            |   7      |  25              |
+-------------+---------------------+------------------+----------------+----------+------------------+
| 2LZM        | ./src/pdbs/2lzm.pdb | V149C            |   A            |   7      |  25              |
+-------------+---------------------+------------------+----------------+----------+------------------+
| 2LZM        | ./src/pdbs/2lzm.pdb | M102L            |   A            |   7      |  25              |
+-------------+---------------------+------------------+----------------+----------+------------------+
| ...         | ...                 | ...              |   ...          |  ...     |  ...             |
+-------------+---------------------+------------------+----------------+----------+------------------+

.. raw:: html

    <div style="text-align: justify;">
    Description of attributes for each column in the table file:
    <div style="margin-left: 40px;">
    <p></p>
    a. <span class="keyword-highlight">Name</span>: Use a single name to label a predicted protein; the name should consist of fewer than 8 alphanumeric characters, with both uppercase and lowercase letters allowed; different rows of data can use the same protein name, but each protein name can only correspond to one <span class="keyword-highlight">PDB_File_Path</span>.
    <p></p>
    b. <span class="keyword-highlight">PDB_File_Path</span>: For the predicted protein, the corresponding <span class="keyword-highlight">PDB</span> file path. <span class="keyword-highlight">PDB</span> files are protein structure files. There are currently various ways to access <span class="keyword-highlight">PDB</span> files, such as through <a href="https://www.rcsb.org/">the RCSB database</a>. In path <span class="keyword-highlight">DDGWizard/src/pdbs</span>, we have also prepared <span class="keyword-highlight">PDB</span> files for testing, corresponding to <span class="keyword-highlight">sample_pred.xls</span>.
    <p></p>
    c. <span class="keyword-highlight">Variation</span>: Specify the specific mutation for which you want to predict ΔΔG, including the mutation site information and amino acid substitution details.
    <p></p>
    d. <span class="keyword-highlight">Chain</span>: Specify the chain identifier of the protein where the specific mutation are located.
    <p></p>
    e. <span class="keyword-highlight">pH</span>: Specify at which pH you want to predict the ΔΔG for the mutation. If you have no specific requirements or preferences regarding pH, you can simply specify it as 7.
    <p></p>
    f. <span class="keyword-highlight">T</span>: Specify at which temperature you want to predict the ΔΔG for the mutation. If you have no specific requirements or preferences regarding temperature, you can simply specify it as 25.
    <p></p>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    (2). <span class="keyword-highlight">--db_folder_path</span>
    This parameter indicates the folder path of the Blast database that you have prepared.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    (3). <span class="keyword-highlight">--db_name</span>
    This parameter indicates the name of the Blast database that you have prepared.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    (4). <span class="keyword-highlight">--if_reversed_data</span>
    This parameter requires you to provide a value of 0 or 1. A value of 0 means only predicting the ΔΔG for the mutations provided in the file, while a value of 1 means also predicting the ΔΔG for the reverse mutations of the mutations provided.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    (5). <span class="keyword-highlight">--blast_process_num</span>
    This parameter requires you to provide an integer greater than 0 and less than 200. It represents the number of processes (multiprocessing) DDGWizard will use for sequence alignment.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    (6). <span class="keyword-highlight">--mode</span>
    Please provide the default value <span class="keyword-highlight">whole</span>.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    (5). <span class="keyword-highlight">--process_num</span>
    This parameter requires you to provide an integer greater than 0 and less than 200. It represents the number of processes (multiprocessing) DDGWizard will use for calculating features (Different from sequence alignment).
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>4. Output</h4>
    There will be an output xls file <span class="keyword-highlight">Pred_ddG.xls</span> located in <span class="keyword-highlight">DDGWizard/src/Pred_Res/</span>, which will record all prediction results.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>5. Notes</h4>
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    (1). When running DDGWizard, you need to <span class="keyword-highlight">cd</span> to the top-level directory of the program to execute the program.
    <p></p>
    (2). DDGWizard supports multi-process handling. If you wish to run multiple instances of DDGWizard to fully utilize your computer's resources, we recommend using the multi-process parameters provided by DDGWizard.
    <p></p>
    <b>Avoid running multiple instances of DDGWizard from the same folder,</b> as the program synchronizes files within the folder, which can cause synchronization errors.
    <p></p>
    If you need to run multiple instances at the same time by yourself, <b>please make multiple copies of the DDGWizard folder and run each instance separately in its own folder.</b>
    <p></p>
    (3). <b>Do not place your files in the top-level folder of DDGWizard.</b> DDGWizard will automatically clean files in the top-level folder to maintain multi-process synchronization.
    <p></p>
    </div>
