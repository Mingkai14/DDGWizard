.. _Generate complete ΔΔG feature set:

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

Generate complete ΔΔG feature set
==================================

.. raw:: html

    <div style="text-align: justify;">
    This guide is intended to show users how to use DDGWizard to generate complete feature set.
    <p></p>
    After feature dimensionality reduction, the DDGWizard prediction program uses the optimal combination of features (69 features) derived from 1547 features to predict ΔΔG, without calculating all the features during running.
    <p></p>
    However, users might need the complete feature set. They may want to generate the full feature set to characterize and analyze the raw ΔΔG data, or use it for their own machine learning projects.
    <p></p>
    We have also prepared a program in DDGWizard for generating the complete feature set.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>1. Example template</h4>
    <p>We first provide you with an example template of running DDGWizard to generate complete feature set, and then explain the specifics of each parameter in detail.</p>
    <p></p>
    You can run the program with (this program also requires the prepared Blast database):
    <p></p>
    <div>

.. raw:: html

    <div class="highlight-default notranslate">
    <div class="highlight">
    <pre style="overflow: scroll">
    $ conda activate DDGWizard
    $ cd DDGWizard/
    $ python Generate_Dataset_Executable.py \
        --raw_dataset_path <b>&lt;the path to xls file of raw data&gt;</b> \
        --db_folder_path <b>&lt;the path to save Blast database&gt;</b> \
        --db_name <b>&lt;the name to assign for Blast database&gt;</b> \
        --if_reversed_data 1 \
        --blast_process_num 4 \
        --mode whole \
        --process_num 4 \
        --container_type <b>&lt;Docker or Singularity&gt;</b>
    </pre>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>2. Parameter details</h4>
    Below are the details of the parameters for program to generate complete  ΔΔG feature set:
    <p></p>
    (1). <span class="keyword-highlight">raw_dataset_path</span>
    <p></p>
    This parameter indicates that you need to provide the path to an <span class="keyword-highlight">xls</span> file, which contains the raw data you want to use to generate ΔΔG feature set.
    <p></p>
    In the path <span class="keyword-highlight">DDGWizard/src</span>, there is a sample file <span class="keyword-highlight">sample.xls</span> that you can use directly for testing and as a reference.
    <p></p>
    This file is similar to the <span class="keyword-highlight">sample_pred.xls</span> file used for prediction.
    <p></p>
    We also list some of the contents of this file here, and provide detailed descriptions of each column's attributes in the table file:
    <p></p>
    <div>

+-------------+---------------------+------------------+----------------+----------+------------------+
| PDB         | Variation           | Chain            | ddG            |   pH     |  T               |
+=============+=====================+==================+================+==========+==================+
| 1AAR        | K6E                 | A                | 0.53           |   5      |  25              |
+-------------+---------------------+------------------+----------------+----------+------------------+
| 1AAR        | K6Q                 | A                | 0.26           |   5      |  25              |
+-------------+---------------------+------------------+----------------+----------+------------------+
| 1AAR        | H68E                | A                | 0.77           |   5      |  25              |
+-------------+---------------------+------------------+----------------+----------+------------------+
| ...         | ...                 | ...              |   ...          |  ...     |  ...             |
+-------------+---------------------+------------------+----------------+----------+------------------+

.. raw:: html

    <div style="text-align: justify;">
    Description of attributes for each column in the table file:
    <div style="margin-left: 40px;">
    <p></p>
    a. <span class="keyword-highlight">PDB</span>: This attribute requires to provide a <span class="keyword-highlight">PDB</span> identifier sourced from <a href="https://www.rcsb.org/">the RCSB database</a>. In the characterization part, the program does not support the use of user-provided <span class="keyword-highlight">PDB</span> files. Users need to provide a <span class="keyword-highlight">PDB</span> identifier that can be searched on <a href="https://www.rcsb.org/">the RCSB database</a> as the name of the predicted protein. The program will automatically download the <span class="keyword-highlight">PDB</span> file from <a href="https://www.rcsb.org/">the RCSB database</a> according to this <span class="keyword-highlight">PDB</span> ID.
    <p></p>
    b. <span class="keyword-highlight">Variation</span>: Specify the specific mutation for which you want to generate features, including the mutation site information and amino acid substitution details.
    <p></p>
    c. <span class="keyword-highlight">Chain</span>: Specify the chain identifier of the protein where the specific mutation are located.
    <p></p>
    d. <span class="keyword-highlight">ddG</span>: This attribute requires to provide the experimental ΔΔG values of the raw data. For users with machine learning needs, this value can serve as the regression target. If users only require the characterization of data features, this attribute can be set to any numerical value without affecting the generation of other features.
    <p></p>
    e. <span class="keyword-highlight">pH</span>: Specify at which pH you want to predict the ΔΔG for the mutation. If you have no specific requirements or preferences regarding pH, you can simply specify it as 7.
    <p></p>
    f. <span class="keyword-highlight">T</span>: Specify at which temperature you want to predict the ΔΔG for the mutation. If you have no specific requirements or preferences regarding temperature, you can simply specify it as 25.
    <p></p>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>3. Output</h4>
    There will be an output <span class="keyword-highlight">csv</span> file <span class="keyword-highlight">features_table.csv</span> located in <span class="keyword-highlight">DDGWizard/src/Features_Table/</span>, which will record complete generated features.
    <p></p>
    </div>


.. raw:: html

    <div style="text-align: justify;">
    <h4>4. Notes</h4>
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


