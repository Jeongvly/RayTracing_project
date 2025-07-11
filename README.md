# 📚 Ray Tracing Project

## 🔧 프로젝트 목적

본 프로젝트의 목적은 **Cube Mapping 환경**을 기반으로 한 **Ray Tracing 엔진**을 직접 구현하는 것입니다. 실제 3D 공간에서의 광선-물체 간 상호작용을 사실적으로 표현하며, 주요 목표는 다음과 같습니다:

- **Phong Reflection Model** 기반의 조명 모델링 구현: Ambient, Diffuse, Specular 성분의 조합을 통해 물체 표면의 질감과 빛 반사를 표현
- **거울 반사 (Reflection)** 및 **투명 효과 (Transparency)** 구현: 광선의 반사와 굴절을 재귀적으로 추적하여 현실적인 광선 경로 표현
- **텍스처**: **UV mapping**과 **super sampling**을 통한 정밀한 텍스처 샘플링
- **Cube Map** 환경 맵핑을 통한 3D 공간 표현

이 프로젝트는 단순 렌더링을 넘어, **실제 광추적 원리**를 직접 구현하고 이해하는데 목적으로 제작하였습니다. 
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

### 5. 'Hit.h'

| 멤버 변수 | 설명 |
|-----------|------|
| `float d` | ray의 시작부터 충돌 지점까지의 거리 |
| `vec3 point` | 충돌한 위치 |
| `vec3 normal` | 충돌 위치에서 표면의 수직 벡터 |
| `vec3 uv` | texture 좌표 |
| 'std::shared_ptr<Object> obj' | 물체의 재질 및 정보를 가져오기 위한 포인터 |

---

### 6. 'Light.h'

| 멤버 변수 | 설명 |
|-----------|------|
| `vec3 pos` | 단순화된 형태의 점 조명 |

---

### 7. 'Ray.h'

| 멤버 변수 | 설명 |
|-----------|------|
| `vec3 start` | ray의 시작 위치 |
| `vec3 dir` | ray의 방향 |

---


## 📌 실행 예시 및 샘플 출력 

<img width="1579" height="884" alt="Image" src="https://github.com/user-attachments/assets/2c6cdde6-d921-47e4-bf81-daaf6a8ea1ca" />




## 🚀 향후 개선 방향

**fresnel 효과 구현**
- 빛의 입사각에 따라 반사와 굴절의 비율이 달리지는 Fresenell 방정식 (Schlick 근사)을 적용해 반사 현실성 향상
