window.onload = function(){
  Particles.init({
    selector: '.background',
    maxParticles: 150,
    connectParticles: 'true',
    speed:.25,
    minDistance: 120,
    sizeVariations: 5,
    color: '#000000',
    responsive: [
      {
        breakpoint: 768,
        options: {
          maxParticles: 200,
          color: '#000000',
          connectParticles: false
        }
      }, {
        breakpoint: 425,
        options: {
          maxParticles: 100,
          connectParticles: true
        }}, {
        breakpoint: 320,
        options: {
          maxParticles: 0
          // disables particles.js
        }
      }
    ]
  });
}