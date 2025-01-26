# Simple Linear Regression Example for WebAssembly

## Using Pyodide
Pyodide is a WebAssembly (Wasm) based project that brings the Python runtime to the browser. It supports many packages, including SciPy and NumPy. To see the Pyodide-based approach for performing linear regression on data points, check out the [Pyodide example](./Pyodide). Simply open the included [linear_regression.html](./Pyodide).

## Using Custom Implementation
You can implement the calculation of linear regression yourself, compile it to WebAssembly, and include it in your web page. To see a custom approach for performing linear regression on data points, check out the [Custom example](./Custom).

### Pipeline
```bash
cd Custom
# Ensure you have emcc version 4.0.1
emcc regression.c -o linear_regression.wasm -s EXPORTED_FUNCTIONS='["_mean", "_linear_regression", "_malloc", "_free"]' --no-entry
# Start the server; the page is located at http://localhost:8080/linear_regression.html
python3 -m http.server 8080
```
