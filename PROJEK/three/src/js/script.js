import * as THREE from 'three';
import * as dat from 'dat.gui';
import {OrbitControls} from 'three/examples/jsm/controls/OrbitControls.js';

const renderer = new THREE.WebGL1Renderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderer.domElement);
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(
    75,
    window.innerWidth / window.innerHeight,
    0.1,
    1000
);

const orbit = new OrbitControls(camera, renderer.domElement);

camera.position.set(0, 2, 5);
orbit.update();

const axesHelper = new THREE.AxesHelper(5);
scene.add(axesHelper);

const geometry = new THREE.BoxGeometry(1, 1, 1);
const material = new THREE.MeshBasicMaterial({color: 0x00ff00});
const cube = new THREE.Mesh(geometry, material);
scene.add(cube);

let step = 0;
let speed = 0.01;

function animate(time) {
    cube.rotation.x = time / 1000;
    cube.rotation.y = time / 1000;

    plane.rotation.z = time / 10000;
    
    step += option.speed;
    sphere.position.y = 10 * Math.abs(Math.sin(step));
    
    renderer.render(scene, camera);

}

const planeGeometry = new THREE.PlaneGeometry(30,30);
const planeMaterial = new THREE.MeshStandardMaterial({
    color: 0xffffff,
    side: THREE.DoubleSide
})

const plane = new THREE.Mesh(planeGeometry, planeMaterial);
scene.add(plane);
plane.rotation.x = -0.5 * Math.PI;

const gridDHelper = new THREE.GridHelper(30);
scene.add(gridDHelper);

const sphereGeometry = new THREE.SphereGeometry(2, 50, 50);
const sphereMaterial = new THREE.MeshStandardMaterial({
    color: 0x0000ff,
    wireframe: false

});
const sphere = new THREE.Mesh(sphereGeometry, sphereMaterial);
scene.add(sphere);

const gui = new dat.GUI();

const ambientLight = new THREE.AmbientLight(0x333333);
scene.add(ambientLight);

const directionalLight = new THREE.DirectionalLight(0xffffff, 0.8);
scene.add(directionalLight);

const option = {
    sphereColor: '#ffea00',
    wireframe: false,
    speed: 0.01
};

sphere.position.x = 5;
gui.addColor(option, 'sphereColor').onChange(function(e){
    sphere.material.color.set(e);
});

gui.add(option, 'wireframe').onChange(function(e){
    sphere.material.wireframe = e;
});

gui.add(option, 'speed', 0, 0.1);


renderer.setAnimationLoop(animate);




