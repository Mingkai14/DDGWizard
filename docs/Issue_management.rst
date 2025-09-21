.. _Issue Management:

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

Issue Management
====================================

.. raw:: html

    <div style="text-align: justify;">
    The Purpose of this page is to show what to do if an issue occurs in installing the model and share debugging options in installing the model obtained from our model testers.
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>Issue Reporting</h4>
    <p>If you encounter any issue in installing the software or in deploying the model please report it (<a href="https://github.com/bioinfbrad/DDGWizard/issues">issue report</a>).</p>
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h4>Most common issues and how to debug </h4>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h5>1. Unable to install the software due to version issues </h5>
    <p>We have successfully tested the Conda installation of the <a href="https://github.com/bioinfbrad/DDGWizard">DDGWizard application</a> on Ubuntu 18.04, Rocky Linux 8.8, and CentOS 7.0. </p>
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h5>2. Unable to run DDGWizard on Windows </h5>
    <p>DDGWizard is not supported on Windows, and it will fail to create the Conda environment under the Windows system. Please run the installation on supported Linux systems, such as  Ubuntu 18.04, Rocky Linux 8.8, and CentOS 7.0.</p>
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h5>3. Old GCC or conda</h5>
    <p>The GCC version is less than 4.8.5, or Conda version is less than 23.0. You can update GCC via your package manager (e.g., running the command line “sudo apt install gcc” under Ubuntu systems). You can update Conda by running the command line “conda update conda”. </p>
    <p></p>
    </div>

.. raw:: html

    <div style="text-align: justify;">
    <h5>4. Not sitting the proper configuration for the conda in the installation</h5>
    <p>The prefix field in the <span class="keyword-highlight">Environment.yml</span> file may not have been set to the correct path of the user’s Conda <span class="keyword-highlight">envs</span> directory. Please edit the prefix field in the <span class="keyword-highlight">Environment.yml</span> file to match the absolute path to the Conda <span class="keyword-highlight">envs</span> directory on your machine. If you don’t  know the exact path of <span class="keyword-highlight">envs</span> directory, please use the command line <span class="keyword-highlight">conda info --envs</span>. </p>
    <p></p>
    </div>


