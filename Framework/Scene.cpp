#include "Scene.h"
//#include "libcurl/curl.h"
#include "curl/curl.h"

void Scene::Init(void)
{
	OnInit();
	_Root->Init();    

    CURLcode res;
    curl_global_init( CURL_GLOBAL_ALL ); //안해도 되나?
    if (CURL* curl = curl_easy_init())
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    //CURL* curl;
    //CURLcode res;

    //curl = curl_easy_init();
    //if (curl) {
    //    curl_easy_setopt(curl, CURLOPT_URL, "https://www.naver.com");
    //    /* example.com is redirected, so we tell libcurl to follow redirection */
    //    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    //    /* Perform the request, res will get the return code */
    //    res = curl_easy_perform(curl);
    //    /* Check for errors */
    //    if (res != CURLE_OK)
    //        fprintf(stderr, "curl_easy_perform() failed: %s\n",
    //            curl_easy_strerror(res));

    //    /* always cleanup */
    //    curl_easy_cleanup(curl);
    //}

}

void Scene::Update(void)
{
	OnUpdate();
	_Root->Update();
}

void Scene::Draw(void)
{
	OnDraw();
	_Root->Draw();
}

void Scene::Destroy(void)
{
	OnDestroy();
	_Root->Destroy();
}

const std::shared_ptr<Object>& Scene::Root(void) {
	return _Root;
}

void Scene::OnInit(void) 
{
}

void Scene::OnUpdate(void) 
{
}

void Scene::OnDraw(void) 
{
}

void Scene::OnDestroy(void) 
{
}