# Chart.js html file exporting for C++11

The goals for this project is to provide a library for exporting data in .html files with the chart.js library.
This can be done by parsing it as a single .html file with script tags. The files should be visible online and offline. This however comes with a compromise explained below.

## .HTML files exported for OFFLINE viewing
Because the entire Chart.js library would have to be parced into the .html file, each .html file will take more diskspace. Estimated to be a couple hundred kB filesize.

## .HTML files exported for ONLINE viewing
Because we can simpily src the script tag with the CDN of Chart.js the file size is cut dramatically, at the cost of requiring a internet connection to view the .html file.

## State of Development

This project is still being actively developed. Currently I have supported a rough draft for Barcharts. Will continue adding support for more chart types over time. I am currently torn between making this a full blown library or attempting to just have a header only option for parcing each chart type individually.

## Author
-   Phillip Cook  (Email @ philcsound@gmail.com)

## License

This project are licenced under the MIT license and as of writting, Chart.Js is licenced under the MIT license as well.