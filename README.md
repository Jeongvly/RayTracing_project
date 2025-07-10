# 📚 Ray Tracing Project

## 🔧 프로젝트 목적

cube mapping을 통해 만든 공간에서 Ray Tracing 구현
Phong model (Ambient, Diffuse, Specular) + reflection + transperency

---

## 📌 개발 환경

- **Language**: C++17  
- **IDE**: Visual Studio 2022  
- **CPU**: Intel

---

## 📌 주요 구조 및 기능

### 1. `Raytracer.h` 

| 멤버 변수 | 설명 |
|-----------|------|
| `int width, height` | 해상도 |
| `Light light` | 조명 위치 |
| `vector<shared_ptr<Object>> objects` | object |

---

| 주요 함수 | 기능 |
|-----------|------|
| `Raytracer(const int& width, const int& height)` | 해상도, 조명, objects 초기화 |
| `Hit FindClosestCollision(Ray& ray)` | ray와 충돌한 가장 가까운 object 위치 반환 |
| `vec3 traceRay(Ray& ray, const int recurseLevel)` | ray와 충돌한 object의 색 반환 |
| `void Render(std::vector<glm::vec4>& pixels)` | pixel 색 결정 |
| `vec3 TransformScreenToWorld(vec2 posScreen)` | Wordl 좌표계(3D) 변환 |

---

### 2. 'object.h'

| 멤버 변수 | 설명 |
|-----------|------|
| `vec3 amb` | Ambient |
| `Vec3 dif` | Diffuse |
| `vec3 spec` | Specular |
| `float alpha` | Specular 강도 |
| 'float reflection' | reflection 강도 |
| 'float transparency' | transparency 강도 |
| 'shared_ptr<Texture> ambTexture' | Texturing Ambient |
| 'shared_ptr<Texture> difTexture' | Texturing Diffuse |

---

| 주요 함수 | 기능 |
|-----------|------|
| `virtual Hit CheckRayCollision(Ray& ray)` | ray와 해당 object의 충돌 정보 반환 |

---

### 3. 'Triangle.h'

| 멤버 변수 | 설명 |
|-----------|------|
| `vec3 v0, v1, v2` | 위치 vector |
| `vec2 uv0, uv1, uv2` | Texture 좌표계 위치 vector |

---

| 주요 함수 | 기능 |
|-----------|------|
| `virtual Hit CheckRayCollision(Ray& ray)` | ray와 해당 object(삼각형)의 충돌 정보 반환 |
| 'bool IntersectRayTriangle(vec3& orig, vec3& dir, vec3& v0, vec3& v1, vec3& v2, vec3& point, vec3& faceNormal, float& t, float& w0, float& w1)' | ray와 object(삼각형) 충돌 체크 |
    
---

### 3. 'Sphere.h'

| 멤버 변수 | 설명 |
|-----------|------|
| `vec3 center` | 중심 vector |
| `float radius` | 반지름 |

---

| 주요 함수 | 기능 |
|-----------|------|
| `virtual Hit CheckRayCollision(Ray& ray)` | ray와 해당 object(구)의 충돌 정보 반환 |
    
---

### 4. 'Texture.h'

| 멤버 변수 | 설명 |
|-----------|------|
| `int width, height, channels` | 이미지 해상도, 채널 |
| `vector<uint8_t> image` | 이미지 |

---

| 주요 함수 | 기능 |
|-----------|------|
| `vec3 GetWrapped(int i, int j)` | 해당 위치 pixel 값 반환 |
| `vec3 InterpolateBilinear` | Linear Interpolation |
| `vec3 SamplePoint(const vec2& uv)` | 좌표계 반환(texture -> image) |
| `vec3 SampleLinear(const vec2& uv)` | 해당 image pixel 값 반환 |

    
---

## 📌 인터페이스 및 사용법

<img width="1579" height="884" alt="Image" src="https://github.com/user-attachments/assets/2c6cdde6-d921-47e4-bf81-daaf6a8ea1ca" />




## 🚀 향후 개선 방향

