window.onload = function(){
  Particles.init({
    selector: '.background',
    maxParticles: 100,
    connectParticles: 'true',
    speed:.25,
    minDistance: 140,
    sizeVariations: 4,
    color: '#000000'
  });
}