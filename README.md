<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url] 
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
<h3 align="center">MSTalgorithms</h3>

  <p align="center">
    Code necessary to test the performance of Kruskal's, Prim's and Boruvka's algorithms with respect to graphs of different characteristics.
    <br />
    <a href="https://github.com/rafmosch/MSTalgorithms">View Demo</a>
    ·
    <a href="https://github.com/rafmosch/MSTalgorithms/issues">Report Bug</a>
    ·
    <a href="https://github.com/rafmosch/MSTalgorithms/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

<!-- [![Product Name Screen Shot][product-screenshot]](https://example.com) -->

This project contains efficient implementations of Prim's, Kruskal's and Boruvka's algorithms, which are commonly used in finding the MST (Minimum Spanning Tree) of a graph.

Kruskal's and Boruvka's are implemented with a union-find structure, implementing union-by-rank and path compression, and Prim's utilizes a priority queue (binary heap). A fibonacci heap may also be used, but was found to causing performance issues.

A random graph generator is also provided, capable of generating edge lists given the number of nodes, vertices, and edge weight range.

Finally, the runtime of the algorithms is conveniently outputted to a `.csv` file in `/data` for further analysis.
<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With
* [![C++][Cpp-badge]][Cpp-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

This is a guide of how to build the interpreter on your machine and run an example program.

### Prerequisites
* g++ 11.3.0
* GNU make 4.3
* git 2.34.1

On Ubuntu:
  ```
  $ sudo apt install git build-essential
  ```

### Compilation

1. Clone the repo on your machine.
  ```
  $ git clone https://github.com/rafmosch/MSTalgorithms
  $ cd MSTalgorithms/
  ```
2. Build
  ```
  $ make clean
  $ make
  ```
  The binary can be found in the `/bin` folder.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage

* Examine how algorithms respond to graphs of different densities.
* Examine runtime of each algorithm varies in repeated executions under random graphs of equal characteristics (node number and density) / runtime variability.
* Make an educated choice on which algorithm to select depending on the application.
  
<!--_For more examples, please refer to the [Documentation](https://example.com)_-->

<p align="right">(<a href="#readme-top">back to top</a>)</p>


See the [open issues](https://github.com/rafmosch/MSTalgorithms/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Your Name - [@raf_mos](https://twitter.com/raf_mos) - raf.mos@princeton.edu

Project Link: [https://github.com/rafmosch/MSTalgorithms](https://github.com/rafmosch/MSTalgorithms)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Vladimir Shestakov, "CSV file generator"](https://gist.github.com/rudolfovich/f250900f1a833e715260a66c87369d15)


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/rafmosch/MSTalgorithms.svg?style=for-the-badge
[contributors-url]: https://github.com/rafmosch/MSTalgorithms/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/rafmosch/MSTalgorithms.svg?style=for-the-badge
[forks-url]: https://github.com/rafmosch/MSTalgorithms/network/members
[stars-shield]: https://img.shields.io/github/stars/rafmosch/MSTalgorithms.svg?style=for-the-badge
[stars-url]: https://github.com/rafmosch/MSTalgorithms/stargazers
[issues-shield]: https://img.shields.io/github/issues/rafmosch/MSTalgorithms.svg?style=for-the-badge
[issues-url]: https://github.com/rafmosch/MSTalgorithms/issues
[license-shield]: https://img.shields.io/github/license/rafmosch/MSTalgorithms.svg?style=for-the-badge
[license-url]: https://github.com/rafmosch/MSTalgorithms/blob/master/LICENSE.md
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/rafael-moschopoulos-50161b281/
[product-screenshot]: images/screenshot.png

[Cpp-badge]: https://img.shields.io/badge/C++-blue?style=for-the-badge&logo=cplusplus&logoColor=ffffff
[Cpp-url]: https://isocpp.org/




