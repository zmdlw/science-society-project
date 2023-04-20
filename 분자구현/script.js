// Scene, camera, renderer 생성
var scene = new THREE.Scene();
var camera = new THREE.PerspectiveCamera(75, window.innerWidth / window.innerHeight, 0.1, 1000);
camera.position.z = 5;
var renderer = new THREE.WebGLRenderer();
renderer.setSize(window.innerWidth, window.innerHeight);
document.getElementById("container").appendChild(renderer.domElement);

// H2O 분자 좌표 정의
var H1 = new THREE.Vector3(-1, 0, 0);
var H2 = new THREE.Vector3(1, 0, 0);
var O = new THREE.Vector3(0, 1, 0);

// H2O 분자 구현
var geometry = new THREE.Geometry();
geometry.vertices.push(H1, H2, O);
geometry.faces.push(new THREE.Face3(0, 1, 2));
var material = new THREE.MeshBasicMaterial({ color: 0xffffff });
var molecule = new THREE.Mesh(geometry, material);
scene.add(molecule);

// 애니메이션 루프 생성
function animate() {
  requestAnimationFrame(animate);
  molecule.rotation.x += 0.01;
  molecule.rotation.y += 0.01;
  renderer.render(scene, camera);
}
animate();
