module.exports = {
  port: 8080,
  server: { baseDir: "./" },
  files: ["build/*.js", "*.html"],
  watchOptions: {
    usePolling: true,
    interval: 100  // Revisa cambios cada 100 milisegundos
  }
};
