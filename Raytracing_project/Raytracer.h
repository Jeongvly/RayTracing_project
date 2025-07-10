#pragma once

#include "Sphere.h"
#include "Ray.h"
#include "Light.h"
#include "Triangle.h"
#include "Square.h"

#include <vector>

namespace hlab
{
	using namespace std;
	using namespace glm;

	class Raytracer
	{
	public:
		int width, height;
		Light light;
		vector<shared_ptr<Object>> objects;
		shared_ptr<Sphere> sphere1;


		Raytracer(const int& width, const int& height)
			: width(width), height(height)
		{
			sphere1 = make_shared<Sphere>(vec3(0.0f, -0.1f, 2.5f), 1.2f);

			sphere1->amb = vec3(0.2f);
			sphere1->dif = vec3(0.0f, 0.0f, 1.0f);
			sphere1->spec = vec3(0.0f);
			sphere1->alpha = 50.0f;
			sphere1->reflection = 0.0f;
			sphere1->transparency = 1.0f;

			objects.push_back(sphere1);

			auto sphere2 = make_shared<Sphere>(vec3(1.3f, -0.4f, 0.5f), 0.5f);

			sphere2->amb = vec3(0.2f);
			sphere2->dif = vec3(0.0f, 0.0f, 1.0f);
			sphere2->spec = vec3(0.0f);
			sphere2->alpha = 50.0f;
			sphere2->reflection = 1.0f;
			sphere2->transparency = 0.0f;

			objects.push_back(sphere2);

			auto sphere3 = make_shared<Sphere>(vec3(-1.0f, -0.6f, 0.4f), 0.3f);

			sphere3->amb = vec3(0.0f, 0.0f, 1.0f);
			sphere3->dif = vec3(0.0f, 0.0f, 1.0f);
			sphere3->spec = vec3(1.0f);
			sphere3->alpha = 200.0f;
			sphere3->reflection = 0.3f;
			sphere3->transparency = 0.3;

			objects.push_back(sphere3);

			auto groundTexture = std::make_shared<Texture>("shadertoy_abstract1.jpg");

			auto ground = make_shared<Square>(vec3(-4.0f, -1.5f, 0.0f), vec3(-4.0f, -1.5f, 5.0f), vec3(4.0f, -1.5f, 5.0f), vec3(4.0f, -1.5f, 0.0f),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			ground->amb = vec3(1.0f);
			ground->dif = vec3(1.0f);
			ground->spec = vec3(1.0f);
			ground->alpha = 10.0f;
			ground->reflection = 0.0f;
			ground->ambTexture = groundTexture;
			ground->difTexture = groundTexture;

			objects.push_back(ground);

			float cubeX = 20.0f;
			float cubeY = 20.0f;
			float cubeZ = 20.0f;

			auto bottomTexture = std::make_shared<Texture>("negy.jpg");

			auto bottomSquare = make_shared<Square>(vec3(cubeX, -cubeY, -cubeZ), vec3(-cubeX, -cubeY, -cubeZ), vec3(-cubeX, -cubeY, cubeZ), vec3(cubeX, -cubeY, cubeZ),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			bottomSquare->amb = vec3(1.0f);
			bottomSquare->dif = vec3(1.0f);
			bottomSquare->spec = vec3(1.0f);
			bottomSquare->alpha = 10.0f;
			bottomSquare->reflection = 0.0f;
			bottomSquare->ambTexture = bottomTexture;
			bottomSquare->difTexture = bottomTexture;

			objects.push_back(bottomSquare);

			auto backTexture = std::make_shared<Texture>("posz.jpg");
			
			auto backSquare = make_shared<Square>(vec3(-cubeX, cubeY, cubeZ), vec3(cubeX, cubeY, cubeZ), vec3(cubeX, -cubeY, cubeZ), vec3(-cubeX, -cubeY, cubeZ),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			backSquare->amb = vec3(1.0f);
			backSquare->dif = vec3(0.0f);
			backSquare->spec = vec3(0.0f);
			backSquare->alpha = 10.0f;
			backSquare->reflection = 0.0f;
			backSquare->ambTexture = backTexture;
			backSquare->difTexture = backTexture;

			objects.push_back(backSquare);

			auto frontTexture = std::make_shared<Texture>("negz.jpg");

			auto frontSquare = make_shared<Square>(vec3(cubeX, cubeY, -cubeZ), vec3(-cubeX, cubeY, -cubeZ), vec3(-cubeX, -cubeY, -cubeZ), vec3(cubeX, -cubeY, -cubeZ),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			frontSquare->amb = vec3(1.0f);
			frontSquare->dif = vec3(0.0f);
			frontSquare->spec = vec3(0.0f);
			frontSquare->alpha = 10.0f;
			frontSquare->reflection = 0.0f;
			frontSquare->ambTexture = frontTexture;
			frontSquare->difTexture = frontTexture;

			objects.push_back(frontSquare);

			auto topTexture = std::make_shared<Texture>("posy.jpg");
			
			auto topSquare = make_shared<Square>(vec3(-cubeX, cubeY, -cubeZ), vec3(cubeX, cubeY, -cubeZ), vec3(cubeX, cubeY, cubeZ), vec3(-cubeX, cubeY, cubeZ),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			topSquare->amb = vec3(1.0f);
			topSquare->dif = vec3(0.0f);
			topSquare->spec = vec3(0.0f);
			topSquare->alpha = 10.0f;
			topSquare->reflection = 0.0f;
			topSquare->ambTexture = topTexture;
			topSquare->difTexture = topTexture;

			objects.push_back(topSquare);

			auto leftTexture = std::make_shared<Texture>("negx.jpg");

			auto leftSquare = make_shared<Square>(vec3(-cubeX, cubeY, -cubeZ), vec3(-cubeX, cubeY, cubeZ), vec3(-cubeX, -cubeY, cubeZ), vec3(-cubeX, -cubeY, -cubeZ),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			leftSquare->amb = vec3(1.0f);
			leftSquare->dif = vec3(0.0f);
			leftSquare->spec = vec3(0.0f);
			leftSquare->alpha = 10.0f;
			leftSquare->reflection = 0.0f;
			leftSquare->ambTexture = leftTexture;
			leftSquare->difTexture = leftTexture;

			objects.push_back(leftSquare);

			auto rightTexture = std::make_shared<Texture>("posx.jpg");

			auto rightSquare = make_shared<Square>(vec3(cubeX, cubeY, cubeZ), vec3(cubeX, cubeY, -cubeZ), vec3(cubeX, -cubeY, -cubeZ), vec3(cubeX, -cubeY, cubeZ),
				vec2(0.0f, 0.0f), vec2(1.0f, 0.0f), vec2(1.0f, 1.0f), vec2(0.0f, 1.0f));

			rightSquare->amb = vec3(1.0f);
			rightSquare->dif = vec3(0.0f);
			rightSquare->spec = vec3(0.0f);
			rightSquare->alpha = 10.0f;
			rightSquare->reflection = 0.0f;
			rightSquare->ambTexture = rightTexture;
			rightSquare->difTexture = rightTexture;

			objects.push_back(rightSquare);

			light = Light{ {0.0f, 0.3f, -0.5f} }; // 화면 뒷쪽
		}

		Hit FindClosestCollision(Ray& ray)
		{
			float closestD = 1000.0; // inf
			Hit closestHit = Hit{ -1.0, dvec3(0.0), dvec3(0.0) };

			for (int l = 0; l < objects.size(); l++)
			{
				auto hit = objects[l]->CheckRayCollision(ray);

				if (hit.d >= 0.0f)
				{
					if (hit.d < closestD)
					{
						closestD = hit.d;
						closestHit = hit;
						closestHit.obj = objects[l];

						// 텍스춰 좌표
						closestHit.uv = hit.uv;
					}
				}
			}

			return closestHit;
		}

		// 광선이 물체에 닿으면 그 물체의 색 반환
		vec3 traceRay(Ray& ray, const int recurseLevel)
		{
			if (recurseLevel < 0)
				return vec3(0.0f);

			// Render first hit
			const auto hit = FindClosestCollision(ray);

			if (hit.d >= 0.0f)
			{
				glm::vec3 color(0.0f);

				// Diffuse
				const vec3 dirToLight = glm::normalize(light.pos - hit.point);

				glm::vec3 phongColor(0.0f);

				const float diff = glm::max(dot(hit.normal, dirToLight), 0.0f);

				// Specular
				const vec3 reflectDir = hit.normal * 2.0f * dot(dirToLight, hit.normal) - dirToLight;
				const float specular = glm::pow(glm::max(glm::dot(-ray.dir, reflectDir), 0.0f), hit.obj->alpha);

				if (hit.obj->ambTexture)
				{
					phongColor += hit.obj->amb * hit.obj->ambTexture->SampleLinear(hit.uv);
				}
				else
				{
					phongColor += hit.obj->amb;
				}

				if (hit.obj->difTexture)
				{
					phongColor += diff * hit.obj->dif * hit.obj->difTexture->SampleLinear(hit.uv);
				}
				else
				{
					phongColor += diff * hit.obj->dif;
				}

				phongColor += hit.obj->spec * specular;

				color += phongColor * (1.0f - hit.obj->reflection - hit.obj->transparency);

				if (hit.obj->reflection)
				{
					const auto reflectedDirection = glm::normalize(2.0f * hit.normal * dot(-ray.dir, hit.normal) + ray.dir);
					Ray reflection_ray{ hit.point + reflectedDirection * 1e-4f, reflectedDirection }; // add a small vector to avoid numerical issue

					color += traceRay(reflection_ray, recurseLevel - 1) * hit.obj->reflection;
				}

				// 참고
				// https://samdriver.xyz/article/refraction-sphere (그림들이 좋아요)
				// https://www.scratchapixel.com/lessons/3d-basic-rendering/introduction-to-shading/reflection-refraction-fresnel (오류있음)
				// https://web.cse.ohio-state.edu/~shen.94/681/Site/Slides_files/reflection_refraction.pdf (슬라이드가 보기 좋지는 않지만 정확해요)
				if (hit.obj->transparency)
				{
					const float ior = 1.5f; // Index of refraction (유리: 1.5, 물: 1.3)

					float eta; // sinTheta1 / sinTheta2
					vec3 normal;

					if (glm::dot(ray.dir, hit.normal) < 0.0f) // 밖에서 안에서 들어가는 경우 (예: 공기->유리)
					{
						eta = ior;
						normal = hit.normal;
					}
					else // 안에서 밖으로 나가는 경우 (예: 유리->공기)
					{
						eta = 1.0f / ior;
						normal = -hit.normal;
					}

					const float cosTheta1 = glm::dot(normal, -ray.dir);
					const float sinTheta1 = glm::sqrt(1 - glm::pow(cosTheta1, 2)); // cos^2 + sin^2 = 1
					const float sinTheta2 = sinTheta1 / eta;
					const float cosTheta2 = glm::sqrt(1 - glm::pow(sinTheta2, 2));

					const vec3 m = glm::normalize(ray.dir + cosTheta1 * normal);
					const vec3 a = -cosTheta2 * normal;
					const vec3 b = sinTheta2 * m;
					const vec3 refractedDirection = glm::normalize(a + b); // transmission

					Ray refractedRay = { hit.point + refractedDirection * 0.001f, refractedDirection };
					color += traceRay(refractedRay, recurseLevel - 1) * hit.obj->transparency;

					// Fresnel 효과는 생략되었습니다.
				}

				return color;
			}

			return vec3(0.0f);
		}

		void Render(std::vector<glm::vec4>& pixels)
		{
			std::fill(pixels.begin(), pixels.end(), vec4(0.0f, 0.0f, 0.0f, 1.0f));

			const vec3 eyePos(0.0f, 0.0f, -1.5f);

#pragma omp parallel for
			for (int j = 0; j < height; j++)
				for (int i = 0; i < width; i++)
				{
					const vec3 pixelPosWorld = TransformScreenToWorld(vec2(i, j));
					Ray pixelRay{ pixelPosWorld, glm::normalize(pixelPosWorld - eyePos) };
					pixels[i + width * j] = vec4(glm::clamp(traceRay(pixelRay, 5), 0.0f, 1.0f), 1.0f);
				}
		}

		vec3 TransformScreenToWorld(vec2 posScreen)
		{
			const float xScale = 2.0f / this->width;
			const float yScale = 2.0f / this->height;
			const float aspect = float(this->width) / this->height;

			// 3차원 공간으로 확장 (z좌표는 0.0)
			return vec3((posScreen.x * xScale - 1.0f) * aspect, -posScreen.y * yScale + 1.0f, 0.0f);
		}
	};
}