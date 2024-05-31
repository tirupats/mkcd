# mkcd

`mkcd` is a command-line utility designed to streamline the process of creating and navigating into directories. Combining the functionality of `mkdir` and `cd` into a single command, `mkcd` helps developers save time and reduce context-switching by automating the creation of directories and changing into them immediately.

## Features

- **Create Directories**: Easily create new directories, including any necessary parent directories.
- **Navigate Automatically**: Automatically change into the newly created directory, reducing the need for multiple commands.
- **Custom Permissions**: Set custom permissions for new directories using the `-m` option.
- **Verbose Mode**: Get detailed output about the actions being performed with the `-v` option.
- **Input Validation**: Ensures that the provided directory path is valid and free from problematic characters.
- **Parent Directories**: Use the `-p` option to create any missing parent directories as needed.

## Installation

### Using Homebrew

To install `mkcd` using Homebrew, follow these steps:

1. Tap the repository:

    ```sh
    brew tap tirupats/homebrew-tap
    ```

2. Install `mkcd`:

    ```sh
    brew install mkcd
    ```

### From Source

To compile and install `mkcd` from source, follow these steps:

1. Clone the repository:

    ```sh
    git clone https://github.com/tirupats/mkcd.git
    cd mkcd
    ```

2. Compile the program:

    ```sh
    gcc -o mkcd mkcd.c
    ```

3. Move the binary to a directory in your PATH, for example:

    ```sh
    sudo mv mkcd /usr/local/bin/
    ```

## Usage

Basic usage of `mkcd`:

```sh
mkcd [options] directory_path

Options:

-p: Create parent directories as needed.
-m mode: Set the file mode (permissions) for the new directory.
-v, --verbose: Enable verbose output.

Example:

mkcd -p -m 755 -v /path/to/new/directory
This command will create the directory /path/to/new/directory with the specified permissions and output detailed information about the process.


Contributing
Contributions are welcome! Please read the contributing guidelines before getting started.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgements
Special thanks to the open-source community for their support and contributions.


