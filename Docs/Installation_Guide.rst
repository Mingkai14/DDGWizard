.. _installation_guide:

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

Installation Guide
==================

.. raw:: html

    <div style="text-align: justify;">
    DDGWizard consists of 3 components: the feature calculation pipeline, that processes raw ΔΔG data and outputs feature-enriched ΔΔG data with 1547 features; the DDGWizard dataset, including 15752 ΔΔG data; and the accurate ΔΔG prediction model.
    <p></p>
    This section explains how to install dependencies for using the DDGWizard's application (there is no need to install anything to access the DDGWizard dataset; it can be directly downloaded).
    <p></p>
    <h4>Installation prerequisites:</h4>
    CentOS 7 or Ubuntu system; GCC version higher than 4.8.5; Conda version higher than 23.0; Git.
    <p></p>
    </div>

.. _`the Prediction Part`:

the ΔΔG Prediction Model (for Predicting ΔΔG)
-----------------------------------------------

.. raw:: html

    <div style="text-align: justify;">
    This subsection is for users who need to use the ΔΔG prediction model. If merely using the prediction model, the partial dependencies of the feature calculation pipeline need to be installed.
    <p></p>
    The installation steps are as follows, which will take about 1 hour.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>1. Git clone the DDGWizard repository</h4>
    <p></p>
    </div>

.. code-block::

    $ git clone https://github.com/Mingkai14/DDGWizard.git

.. raw:: html

    <div style="text-align: justify;">
    <h4>2. Config and install conda virtual environment</h4>
    <p></p>
    <p>There is an <span class="keyword-highlight">environment.yml</span> file located in the path <span class="keyword-highlight">DDGWizard/src</span>, which is the Conda environment configuration file.</p>
    <p></p>
    <p>Open this file with your text editor (e.g., nano, vim, vi, etc.). Here we use vi as an example:</p>
    <p></p>
    </div>

.. code-block::

    $ cd DDGWizard/src/
    $ vi environment.yml

.. raw:: html

    <div style="text-align: justify;">
    <p>Modify the <span class="keyword-highlight">prefix</span>, <b>which is on the last line</b>. <b>Change the prefix to your local <span class="keyword-highlight">conda envs folder</span>.</b></p>
    <p></p>
    After changing, the <span class="keyword-highlight">prefix</span> should be <span class="keyword-highlight">prefix: <b>&lt;the path to your conda envs folder&gt;</b>/DDGWizard</span>.
    <p></p>
    If you don't know how to find the path to local <span class="keyword-highlight">conda envs folder</span>, you can use command:
    <p></p>
    </div>

.. code-block::

     $ conda info --envs

.. raw:: html

    <div style="text-align: justify;">
    <p>Once you have changed the <span class="keyword-highlight">prefix</span> of <span class="keyword-highlight">environment.yml</span> file, you can use Conda commands to create a Conda virtual environment and install dependencies. This may take some time.</p>
    <p></p>
    </div>

.. code-block::

     $ conda env create -f environment.yml

.. raw:: html

   <div style="text-align: justify;">
   <h4>3. Configure Modeller</h4>
   <p></p>
   The Modeller software is used for homology or comparative modeling of protein three-dimensional structures. You can find more information about Modeller <a href="https://salilab.org/modeller/">here</a>. In DDGWizard, Modeller is used to construct PDB protein structure files of mutations based on the user's input of wild-type PDB protein structure files.
   <p></p>
   Modeller has already been installed when creating Conda environment. But to allow our program to use it, you need to have a license of the Modeller and configure it.
   <p></p>
   Please enter <a href="https://salilab.org/modeller/registration.html">the official Modeller website</a>, register an account and obtain a license. You can simply follow their instructions to achieve this.
   <p></p>
   Once you obtain the license of the Modeller, please input the license into installed Modeller's configuration file. You can find it under the <span class="keyword-highlight">Conda envs folder</span>.
   <p></p>
   Enter your local <span class="keyword-highlight">Conda envs folder</span>, and open the Modeller's configuration file:
   <p></p>
   </div>

.. raw:: html

    <div class="highlight-default notranslate">
    <div class="highlight">
    <pre style="overflow: scroll">
    $ cd <b>&lt;the path to your conda envs folder&gt;</b>
    $ vi DDGWizard/lib/modeller-10.4/modlib/modeller/config.py
    </pre>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <p>Replace the XXXX to your license. Save and close it.</p>
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>4. Configure DSSP</h4>
    The DSSP is software used to calculate the RSA (relative surface area) and secondary stuctures of <span class="keyword-highlight">PDB</span> files.
    <p></p>
    Due to the version conflict issues, you must do operations below to make DSSP can be used of our program.
    <p></p>
    Enter your local <span class="keyword-highlight">Conda envs folder</span>, then enter <span class="keyword-highlight">bin folder</span>, and copy <span class="keyword-highlight">mkdssp</span> (a modified version of dssp) as <span class="keyword-highlight">dssp</span>:
    <p></p>
    </div>

.. raw:: html

    <div class="highlight-default notranslate">
    <div class="highlight">
    <pre style="overflow: scroll">
    $ cd <b>&lt;the path to your conda envs folder&gt;</b>
    $ cd DDGWizard/bin/
    $ cp mkdssp dssp
    </pre>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>5. Make sure the programs of the DDGWizard have the executable permission</h4>
    The programs of DDGWizard need the executable permission to run.
    <p></p>
    Return to the DDGWizard program folder and execute the command:
    <p></p>
    </div>

.. raw:: html

    <div class="highlight-default notranslate">
    <div class="highlight">
    <pre style="overflow: scroll">
    $ cd <b>&lt;the path to the parent folder of DDGWizard program folder&gt;</b>/DDGWizard
    $ chmod -R +x .
    </pre>
    </div>
    </div>

.. _`the Characterization part`:

the Feature Calculation Pipeline (for Outputting Feature-Enriched ΔΔG Data)
------------------------------------------------------------------------------

.. raw:: html

    <div style="text-align: justify;">
    This subsection is for users who need to use the feature calculation pipeline. It can assist users in processing input raw ΔΔG data and outputting feature-enriched new data, including 1574 features that completed calculations. It can facilitate further analysis, feature selection, and machine learning.
    <p></p>
    The feature calculation pipeline requires additional dependencies. It uses certain R-based packages and certain cross-platform software, thus requiring dependencies on the R language and the container system.
    <p></p>
    <h4>Additional prerequisites:</h4>
    <span class=keyword-highlight>R</span>, <span class=keyword-highlight>Docker</span> or <span class=keyword-highlight>Singularity</span> (Only one container system is needed).
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>1. Complete the 1-5 steps of "the ΔΔG Prediction Model" part</h4>
    <p></p>
    Perform the same operations as steps 1-5 in "the ΔΔG Prediction Model" part.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>2. Install Bio3D</h4>
    We assume that <span class="keyword-highlight">R</span> is already installed on your Linux system (You can download and install <span class="keyword-highlight">R</span> from <a href="https://cran.r-project.org/">the official R website</a>).
    <p></p>
    The R-based package <span class="keyword-highlight">Bio3D</span> used to calculate the NMA (normal mode analysis) features.
    <p></p>
    Open your <span class="keyword-highlight">R</span> and use following commands to install package <span class="keyword-highlight">Bio3D</span>:
    <p></p>
    </div>

.. code-block::

    $ R
    install.packages("bio3d")

.. raw:: html

    <div style="text-align: justify;">
    <h4>3. Download the container image files</h4>
    The feature calculation pipeline of DDGWizard will automatically call the container system to utilize the resources from the container image files. Before this, you need to download the container image files first.
    <p></p>
    Please download the following two files: <span class="keyword-highlight">myprof.tar</span> (128MB) and <span class="keyword-highlight">myprof.sif</span> (360MB) from <a href="https://zenodo.org/records/12817843">https://zenodo.org/records/12817843</a>, and copy them to the path: <span class="keyword-highlight">DDGWizard/src/Prof_Source</span> within the DDGWizard program folder:
    <p></p>
    </div>

.. raw:: html

    <div class="highlight-default notranslate">
    <div class="highlight">
    <pre style="overflow: scroll">
    $ cp <b>&lt;the path to myprof.tar&gt;</b>/myprof.tar DDGWizard/src/Prof_Source
    $ cp <b>&lt;the path to myprof.sif&gt;</b>/myprof.sif DDGWizard/src/Prof_Source
    </pre>
    </div>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>4. Config container</h4>
    Your Linux system needs to have at least one of the two container systems, <span class="keyword-highlight">Docker</span> or <span class="keyword-highlight">Singularity</span>, installed and configured in order for the feature calculation pipeline of DDGWizard to run. You can download and install them from <a href="https://www.docker.com/">the official Docker websites</a> and <a href="https://sylabs.io/singularity/">the official Singularity websites</a>.
    <p></p>
    You can choose one of <span class="keyword-highlight">Docker</span> or <span class="keyword-highlight">Singularity</span> to be used by the feature calculation pipeline. If you choose <span class="keyword-highlight">Docker</span>, you will need to perform an additional step:
    <p></p>
    </div>

.. code-block::

    $ docker load -i DDGWizard/src/Prof_Source/myprof.tar

.. raw:: html

    <div style="text-align: justify;">
    If you choose Singularity, no additional configuration is required.
    <p></p>
    </div>


